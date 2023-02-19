/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:40:32 by victor            #+#    #+#             */
/*   Updated: 2023/02/19 13:23:16 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hangman.h"

char	*ft_tried_letters(char c, int i)
{
	char *tried;

	tried = malloc(sizeof(char) * i);
	if (!tried)
		return (NULL);
	tried[i] = c;
	tried[i+1] = '\0';
	return (tried);
}

void	ft_print_mot(char *mot, char *hidden)
{
	int	i = 0;
	
	while (i < ft_strlen(mot) - 1)
	{
		if (hidden[i] == '*')
			 printf("  *"); //rajouter couleur ?
		else
			printf("  \033[32m%c\033[0m", hidden[i]);
		i++;
	}
	printf("\n\n");
}

void	ft_print_echaffau(int tries)
{
	if (tries == 6)
		printf("    |====||\n    |    ||\n         ||	TRIES : %d\n         ||\n        /__\\\n", tries);
	else if (tries == 5)
		printf("    |====||\n    |    ||\n   o     ||	TRIES : %d\n         ||\n        /__\\\n", tries);
	else if (tries == 4)
		printf("    |====||\n    |    ||\n    o    ||	TRIES : %d\n    |    ||\n        /__\\\n", tries);
	else if (tries == 3)
		printf("    |====||\n    |    ||\n    o    ||	TRIES : %d\n   -|    ||\n        /__\\\n", tries);
	else if (tries == 2)
		printf("    |====||\n    |    ||\n    o    ||	TRIES : %d\n   -|-   ||\n        /__\\\n", tries);
	else if (tries == 1)
		printf("    |====||\n    |    ||\n    o    ||	TRIES : %d\n   -|-   ||\n   /   /__\\\n", tries);
	else if (tries == 0)
		printf("    |====||\n    |    ||\n    o    ||	TRIES : %d\n   -|-   ||\n   / \\  /__\\\n", tries);
	printf("\n");
}

char *ft_print_used(char *mot, int pos)
{
	static char	*used;
	int	i = 0;

	used = malloc(sizeof(char) * ft_strlen(mot) + 6);
	if (!used)
		return (NULL);
	used = ft_get_letter(used, pos);
	printf("USed[%d] : %c\n", pos, used[0]);
	printf("Used Letters :\n");
	i = 0;
	while (i < pos)
	{
		printf("%c --", used[i]);
		i++;
	}
	printf("\n");
	//printf("used : %s\n", used);
	return (used);
}

// int	main(void)
// {
// 	char	*mot;

// 	mot = ft_select_word(1, 1830);
// 	ft_print_echaffau(5);
// 	ft_print_mot(mot, "armoire");
// 	printf("%s", mot);
// 	ft_print_used(mot, 2);
	
// 	// mot = ft_select_word(1, 1830);
// 	// ft_print_echaffau(3);
// 	// ft_print_mot(mot, "b**c");
// 	// printf("%s", mot);
// 	return (0);
// }
