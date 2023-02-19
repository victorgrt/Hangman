/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoret <vgoret@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:11:33 by vgoret            #+#    #+#             */
/*   Updated: 2022/12/12 16:00:21 by vgoret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
! GET_NEXT_LINE : lire un fichier lignes par lignes
*/

#include "get_next_line.h"
/*
!recupfile : Cette fonction nous sert a lire un fichier (read).
On commence par malloc une chain de characteres en fonction du BUFFER_SIZE 
donne et on le securise. Ensuite on va lire le fichier grace a read dans la 
chaine lu. On concatene nos chaines lu et save dans save afin qu'on ait 
l'entierete du fichier dans save (boucle ouvert > 0 infinie).
Finalement, on free lu car on en aura plus besoin et on return save
qui contient ce qu'on a lu.
*/

char	*recupfile(char *save, int fd)
{
	char	*lu;
	int		ouvert;

	lu = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!lu)
		return (NULL);
	ouvert = 1;
	while (ouvert > 0)
	{
		ouvert = read(fd, lu, BUFFER_SIZE);
		if (ouvert < 0)
		{
			free(lu);
			return (NULL);
		}
		lu[ouvert] = 0;
		save = ft_strjoin(save, lu);
	}
	free(lu);
	return (save);
}

/*
!recupline : Cette fonction nous sert a recuperer une seule ligne.
On commence par s'assurer que save n'est pas vide. Ensuite, on va parcourir
save tant qu'on ne trouve ni '\n' ni '\0' en ajoutant 1 pour bien prendre le \n.
On malloc une nouvelle chaine en fonction de la len qu'on a obtenu et on le
securise. Et maintenant, tant que notre compteur est inf a len, on va remplir
la nouvelle chaine des characteres de save. Finalement, on ajoute un '\0' a 
la fin de str pour pas avoir de soucis de memoires et on la return.
*/

char	*recupline(char *save)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	if (save == NULL)
		return (NULL);
	if (save[len] == 0)
		return (NULL);
	while (save[len] != '\0' && save[len] != '\n')
		len++;
	if (save[len] == '\n')
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/* 
! trimming_static :
Il se peut qu'on ait lu un partie de la liste suivante a cause de 
BUFFER_SIZE donc on a besoin de trimmer save pour s'assurer qu'on
ne perdre pas de donnees.
On a besoin d'un buffeur pour ne pas perdre de donnees et de deux compteurs.
On commence par verifier que save n'est pas vide. Ensuite on va parcourir la
chaine jusqu'a trouve un '\n' ou '\0' + 1 pour avoir le '\n'.
Ensuite on malloc notre buffeur avec ft_strlen et i et on le securise.
Maintenant on va remplir notre buffeur avec les characteres de save
tant qu'on a pas trouve notre prochain '\0'. Quand c'est fini, on ajoute
un '\0' a la main et on return notre buffer.
*/

char	*trimming_static(char *save)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\n')
		i++;
	if (ft_strlen(save) == 0)
		return (free(save), NULL);
	buff = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!buff)
		return (free(buff), free(save), NULL);
	j = 0;
	while (save[i] != '\0')
	{
		buff[j] = save[i];
		i++;
		j++;
	}
	buff[j] = '\0';
	return (free(save), buff);
}

/*
! get_next_line :
On defini notre variable statique ainsi qu'une nouvelle chaine. Ensuite on
verifie que notre parametre et notre BUFFER_SIZE sont supperieurs a 0.
On va commencer par appeler notre fonction recupfile qui va recuperer
toutes les lignes de notre fichier et lire toutes les lignes (open et read).
Maintenant on va appeler notre fonction recupline qui va recuperer
lignes par lignes et on va stocker ca dans line pour plus tard.
Finalement on appelle notre fonction grostrimard (dans save) pour s'assurer
qu'on a bien une seule ligne dans save et pas de characteres en trop (ligne
suivante). Finalement, on va return line qui contient donc une seule ligne
du fichier.
*/

char	*get_next_line(int fd)
{
	static char	*save[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[fd] = recupfile(save[fd], fd);
	line = recupline(save[fd]);
	save[fd] = trimming_static(save[fd]);
	return (line);
}

/*#include <stdio.h>
int main(void)
{
	int fd;
	// int	i = 1;
	char	*res;
	fd = open("test.txt", O_RDONLY);

	res = get_next_line(fd);
	while (res)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/