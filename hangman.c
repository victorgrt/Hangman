/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hangman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:59:11 by victor            #+#    #+#             */
/*   Updated: 2023/02/19 21:39:13 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hangman.h"

int hangman()
{
    char    *mot;
    char    *hidden;
    char    *used;
    char    letter;
    int     i = 0;
    int     life = 6;
    int     printed;

    used = malloc(sizeof(char) * 26);
    if (!used)
        return 0;
    mot = ft_select_word(1, 1830);
    //printf("Mot : %s\n", mot);
    hidden = ft_hidden_word(mot);
    ft_print_all(mot, hidden, NULL, 6);
    while (ft_cmp(mot, hidden) == 0)
    {
        printed = 0;
        if (life == 0)
        {
            ft_print_echaffau(life);
            printf("  ▄████  ▄▄▄      ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███\n ██▒ ▀█▒▒████▄   ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒\n▒██░▄▄▄░▒██  ▀█▄ ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒\n░▓█  ██▓░██▄▄▄▄██▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  \n░▒▓███▀▒ ▓█   ▓██▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒\n ░▒   ▒  ▒▒   ▓▒█░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░\n  ░   ░   ▒   ▒▒ ░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░\n░ ░   ░   ░   ▒  ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ \n      ░       ░  ░      ░      ░  ░       ░ ░        ░     ░  ░   ░     \n                                                    ░                   \n\nTon mot était : \033[1m\033[31m%s\033[0", mot);
            return (0);
        }
        //scanf("%c", &letter);
        scanf("%c", &letter);
        if (ft_check(mot, letter) == 1)
        {
            ft_reponse(mot, hidden, letter);
            used[i] = letter;
            //used[i+1] = '\0';
            ft_print_all(mot, hidden, used, life);
            i++;
            printed = 1;
        }
        else
        {
            used[i] = letter;
            used[i+1] = '\0';
            if (printed == 0)
                ft_print_all(mot, hidden, used, life);
            i++;
            life--;
        }
    }
    printf("▓██   ██▓ ▒█████   █    ██     █     █░ ██▓ ███▄    █\n ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓█░ █ ░█░▓██▒ ██ ▀█   █ \n  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒█░ █ ░█ ▒██▒▓██  ▀█ ██▒\n  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ░█░ █ ░█ ░██░▓██▒  ▐▌██▒\n  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░░██▒██▓ ░██░▒██░   ▓██░\n   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▓░▒ ▒  ░▓  ░ ▒░   ▒ ▒ \n ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░      ▒ ░ ░   ▒ ░░ ░░   ░ ▒░\n ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░   ░   ▒ ░   ░   ░ ░ \n ░ ░         ░ ░     ░            ░     ░           ░ \nBravo tu as trouvé le mot : \033[1m\033[32m%s\033[0\n", mot);
    return (1);
}

int main() 
{
    hangman();
    return 0;
}