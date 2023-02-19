/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hangman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:59:11 by victor            #+#    #+#             */
/*   Updated: 2023/02/19 13:15:59 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hangman.h"

void ft_setup_used(char *used)
{
    int i = 0;

    while (used[i])
    {
        used[i] = '0';
        i++;
    }
}

void    hangman(char *mot, char *hidden)
{
    int life = 6;
    int pos = 0;
    int i = 0;
    //char    letter;
    static  char    *used;

    used = malloc(sizeof(char) * (ft_strlen(mot) + 6));
    if(!used)
        return ;
    ft_setup_used(used);
    printf("ici%s\n", used);
    if (i == 0)
    {
        ft_print_echaffau(life);
        ft_print_mot(mot, hidden);
        used = ft_print_used(mot, i);
        if (ft_check(mot, used[i]) == 1)
            ft_reponse(mot, hidden, used[i]);
        else
            life--;
    }
    while (i < life)
    {
        if (ft_cmp(mot, hidden) == 1)
        {
            printf("▓██   ██▓ ▒█████   █    ██     █     █░ ██▓ ███▄    █\n ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓█░ █ ░█░▓██▒ ██ ▀█   █ \n  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒█░ █ ░█ ▒██▒▓██  ▀█ ██▒\n  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ░█░ █ ░█ ░██░▓██▒  ▐▌██▒\n  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░░██▒██▓ ░██░▒██░   ▓██░\n   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▓░▒ ▒  ░▓  ░ ▒░   ▒ ▒ \n ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░      ▒ ░ ░   ▒ ░░ ░░   ░ ▒░\n ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░   ░   ▒ ░   ░   ░ ░ \n ░ ░         ░ ░     ░            ░     ░           ░ \nBravo tu as trouvé le mot : \033[4m %s \033[0\n", mot);
            return;
        }
        ft_print_echaffau(life);
        ft_print_mot(mot, hidden);
        //ft_print_used(mot, pos);
        used = ft_print_used(mot, pos);
        if (ft_check(mot, used[i]) == 1)
        {
            ft_reponse(mot, hidden, used[i]);
        }
        else
            life--;
        pos++;
    }
    printf("  ▄████  ▄▄▄      ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███\n ██▒ ▀█▒▒████▄   ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒\n▒██░▄▄▄░▒██  ▀█▄ ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒\n░▓█  ██▓░██▄▄▄▄██▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  \n░▒▓███▀▒ ▓█   ▓██▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒\n ░▒   ▒  ▒▒   ▓▒█░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░\n  ░   ░   ▒   ▒▒ ░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░\n░ ░   ░   ░   ▒  ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ \n      ░       ░  ░      ░      ░  ░       ░ ░        ░     ░  ░   ░     \n                                                    ░                   \n\nTon mot était : \033[4m%s\033[0", mot);    
}

int main() 
{
   // char *tried;
    char *mot = ft_select_word(1, 1830);
    char *hidden = ft_hidden_word(mot);
    printf("%s\n", mot);
    hangman(mot, hidden);
    //tried = ft_tried_letters(lettre, 0); 
    // ft_print_echaffau(tries);
    //ft_print_mot(mot, hidden, NULL);
   // printf("Mot : %s\nHidden : %s\n", mot, hidden);
    // ft_print_echaffau(tries);
    // ft_print_mot(mot, hidden, test);
    // while (tries != 0 || ft_win(mot, hidden) == 0)
    // {
    //     if (ft_cmp(mot, hidden) == 0) //si c pas pareil, on print echaffau et 
    //     {
    //         if (ft_check(mot, test[i]) == 1)
    //             ft_reponse(mot, hidden, test[i]);
    //         ft_print_echaffau(tries);
    //         ft_print_mot(mot, hidden, NULL);
    //         test[i] = ft_get_letter();

    //     }
    //     else if (ft_cmp(mot, hidden) == 1) //si les deux son pareils alors win
    //     {
    //         printf("\nBravo tu as trouvé le mot : \033[4m%s\033[0m\n", mot);
    //         return (0);
    //     }
    //     else
    //         tries--;
    // }
    // printf(" Game Over\nLe mot était : %s\n%s", mot, test);
    return 0;
}