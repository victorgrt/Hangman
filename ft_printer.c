/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:40:32 by victor            #+#    #+#             */
/*   Updated: 2023/02/19 18:25:32 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hangman.h"

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
	printf("\n");
}

void	ft_print_echaffau(int tries)
{
	if (tries == 6)
		printf("    |====||\n    |    ||\n         ||	TRIES : %d\n         ||\n        /__\\\n", tries);
	else if (tries == 5)
		printf("    |====||\n    |    ||\n    o    ||	TRIES : %d\n         ||\n        /__\\\n", tries);
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

void	ft_print_used(char *used_letters)
{
	int	i = 0;
	
	printf("Lettres essayées : ");
	while (used_letters[i])
	{
		printf(" %c ", used_letters[i]);
		i++;
	}
	printf("\n");
}

void	ft_print_all(char *mot, char *hidden, char *used, int life)
{
	ft_print_echaffau(life);
	ft_print_mot(mot, hidden);
	if (used)
	{
		write(1, "\n", 1);
		ft_print_used(used);
		write(1, "\n", 1);
	}
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
