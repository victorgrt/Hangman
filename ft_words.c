/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:40:30 by victor            #+#    #+#             */
/*   Updated: 2023/02/19 03:04:35 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hangman.h"
#include <stdio.h>


int	random_generator(int min, int max)
{
	struct	timeval tv;
	int	range;
	int	random_number;
	unsigned int seed;

	range = max - min + 1;
	gettimeofday(&tv, NULL);
	seed = tv.tv_sec + tv.tv_usec;
	srandom(seed);
	random_number = (int)(double)range * random() / (RAND_MAX + 1.0) + min; 
	return (random_number);
}

char	*ft_select_word(int min, int max)
{
	int	random_number, fd, compteur;
	char	*mot;

	random_number = random_generator(min, max);
	fd = open("words.txt", O_RDONLY);
	mot = get_next_line(fd);
	while (compteur < random_number)
	{
		free(mot);
		mot = get_next_line(fd);
		compteur++;
	}
	if (compteur == random_number)
		mot = get_next_line(fd);
	close(fd);
	return (mot);
}

char	*ft_hidden_word(char *mot)
{
	char	*hidden;
	int	i = 0;
	int	size = ft_strlen(mot) - 1;
		
	hidden = malloc(sizeof(char) * size);
	if (!hidden)
		return (NULL);
	while (i < size)
	{
		if (size <= 4)
			hidden[i] = '*';
		else if (!(mot[i] >= 'a' && mot[i] <= 'z'))
			hidden[i] = mot[i];
		else if (size <= 7)
		{
			if (i == 0)
				hidden[i] = mot[i];
			else
				hidden[i] = '*';
		}
		else if (size <= 9)
		{
			if (i == 0)
				hidden[i] = mot[i];
			else if (i == size - 1)
				hidden[size - 1] = mot[size - 1];
			else
				hidden[i] = '*';
		}
		else if (size >= 10)
		{
			if (i == 0 || i == size/2)
				hidden[i] = mot[i];
			else if (i == size - 1)
				hidden[size - 1] = mot[size - 1];
			else if (i == size/2)
				hidden[size/2] = mot[size/2];
			else
				hidden[i] = '*';
		}
		i++;
	}
	return (hidden);
}

// int main(void)
// {
// 	int fd;
// 	char	*mot;
// 	char	*mot2;
// 	char	*res;
// 	fd = open("words.txt", O_RDONLY);

// 	res = get_next_line(fd);
// 	while (res)
// 	{
// 		//printf("%s", res);
// 		free(res);
// 		res = get_next_line(fd);
// 	}
// 	mot = ft_select_word(1, 1830);
// 	mot2 = ft_hidden_word(mot);
// 	printf("%s\n", mot);
// 	printf("%s\n", mot2);
// 	close(fd);
// 	return (0);
// }