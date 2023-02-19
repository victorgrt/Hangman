/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hangman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 18:59:11 by victor            #+#    #+#             */
/*   Updated: 2023/02/19 18:30:01 by victor           ###   ########.fr       */
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

// void    hangman(char *mot, char *hidden)
// {
//     int life = 6;
//     int pos = 0;
//     int i = 0;
//     char    letter;
//     static  char    *used;

//     used = malloc(sizeof(char) * (ft_strlen(mot) + 6));
//     if(!used)
//         return ;
//     ft_setup_used(used);
//     printf("ici%s\n", used);
//     if (i == 0)
//     {
//         ft_print_echaffau(life);
//         ft_print_mot(mot, hidden);
//         letter = ft_get_letter();
//         used[i] = letter;
//         if (ft_check(mot, letter) == 1)
//             ft_reponse(mot, hidden, letter);
//         else
//             life--;
//     }
//     while (i < life)
//     {
//         if (ft_cmp(mot, hidden) == 1)
//         {
//             printf("▓██   ██▓ ▒█████   █    ██     █     █░ ██▓ ███▄    █\n ▒██  ██▒▒██▒  ██▒ ██  ▓██▒   ▓█░ █ ░█░▓██▒ ██ ▀█   █ \n  ▒██ ██░▒██░  ██▒▓██  ▒██░   ▒█░ █ ░█ ▒██▒▓██  ▀█ ██▒\n  ░ ▐██▓░▒██   ██░▓▓█  ░██░   ░█░ █ ░█ ░██░▓██▒  ▐▌██▒\n  ░ ██▒▓░░ ████▓▒░▒▒█████▓    ░░██▒██▓ ░██░▒██░   ▓██░\n   ██▒▒▒ ░ ▒░▒░▒░ ░▒▓▒ ▒ ▒    ░ ▓░▒ ▒  ░▓  ░ ▒░   ▒ ▒ \n ▓██ ░▒░   ░ ▒ ▒░ ░░▒░ ░ ░      ▒ ░ ░   ▒ ░░ ░░   ░ ▒░\n ▒ ▒ ░░  ░ ░ ░ ▒   ░░░ ░ ░      ░   ░   ▒ ░   ░   ░ ░ \n ░ ░         ░ ░     ░            ░     ░           ░ \nBravo tu as trouvé le mot : \033[4m %s \033[0\n", mot);
//             return;
//         }
//         ft_print_echaffau(life);
//         ft_print_mot(mot, hidden);
//         ft_print_used(mot, pos);
//         letter = ft_get_letter();
//         used[i] = letter;
//         if (ft_check(mot, letter) == 1)
//             ft_reponse(mot, hidden, letter);
//         else
//             life--;
//         pos++;
//     }
//     printf("  ▄████  ▄▄▄      ███▄ ▄███▓▓█████     ▒█████   ██▒   █▓▓█████  ██▀███\n ██▒ ▀█▒▒████▄   ▓██▒▀█▀ ██▒▓█   ▀    ▒██▒  ██▒▓██░   █▒▓█   ▀ ▓██ ▒ ██▒\n▒██░▄▄▄░▒██  ▀█▄ ▓██    ▓██░▒███      ▒██░  ██▒ ▓██  █▒░▒███   ▓██ ░▄█ ▒\n░▓█  ██▓░██▄▄▄▄██▒██    ▒██ ▒▓█  ▄    ▒██   ██░  ▒██ █░░▒▓█  ▄ ▒██▀▀█▄  \n░▒▓███▀▒ ▓█   ▓██▒██▒   ░██▒░▒████▒   ░ ████▓▒░   ▒▀█░  ░▒████▒░██▓ ▒██▒\n ░▒   ▒  ▒▒   ▓▒█░ ▒░   ░  ░░░ ▒░ ░   ░ ▒░▒░▒░    ░ ▐░  ░░ ▒░ ░░ ▒▓ ░▒▓░\n  ░   ░   ▒   ▒▒ ░  ░      ░ ░ ░  ░     ░ ▒ ▒░    ░ ░░   ░ ░  ░  ░▒ ░ ▒░\n░ ░   ░   ░   ▒  ░      ░      ░      ░ ░ ░ ▒       ░░     ░     ░░   ░ \n      ░       ░  ░      ░      ░  ░       ░ ░        ░     ░  ░   ░     \n                                                    ░                   \n\nTon mot était : \033[4m%s\033[0", mot);    
// }

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
    printf("Mot : %s\n", mot);
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
            used[i+1] = '\0';
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

//j'ai besoin de quoi? Un mot généré, un hidden, un used et 
// Deroulement du jeu : - generation du mot, affichage de l'echaffau et du hidden.
// - jusqu'a que hidden == mot || life = 0 -> scanf lettre, si lettre dans mot -> on remplace dans hidden toutes les occurences et
// on ajoute lettre dans used; On affiche echaffau, hidden et used. Sinon (lettre pas dans mot), on enleve une vie, on actualise used
// et on affiche echaffau hidden et used. 
//Si life == 0 printf (game over) 
//Si hidden == mot printf (you win);


/* !!TODO!! */

int main() 
{
    hangman();
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
// 
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