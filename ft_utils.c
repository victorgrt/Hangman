/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:46:17 by victor            #+#    #+#             */
/*   Updated: 2023/02/19 14:41:07 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hangman.h"

int ft_victory(char *mot, char *hidden)
{
    int i = 0;

    while (mot[i])
    {
        if (mot[i] != hidden[i])
            return (0);
        i++;
    }
    return (1);
}

void ft_reponse(char *mot, char *hidden, char c)
{
    int i = 0;
    int j;

    while (hidden[i])
    {
        if (mot[i] == c)
        {
            j = i + 1;
            while (j < ft_strlen(mot) - 1)
            {
                if (mot[j] == c)
                    hidden[j] = c;
                j++;
            }
            hidden[i] = c;
        }
        i++;
    }
}

char    ft_get_letter()
{
    char lettre;

    printf("Enter a letter : \n");
    lettre = scanf("%c", &lettre);
    return (lettre);
}

int ft_win(char *mot, char *hidden)
{
    int i = 0;

    while (hidden[i] && mot[i])
    {
        if (hidden[i] == mot[i])
            i++;
        return (0);
    }
    return (1);
}

int ft_cmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    return (1);
}

int ft_check(char *mot, char c)
{
    int i = 0;

    while (mot[i])
    {
        if (mot[i] == c)
            return (1);
        i++;
    }
    return (0);
}