/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hangman.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 13:40:40 by victor            #+#    #+#             */
/*   Updated: 2023/02/19 21:29:47 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HANGMAN_H
# define HANGMAN_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "./gnl/get_next_line.h"

char	*ft_select_word(int min, int max);
int     random_generator(int min, int max);
char	*ft_hidden_word(char *mot);

char	*ft_tried_letters(char c, int tries);
int     ft_cmp(char *s1, char *s2);
int     ft_check(char *mot, char c);
void    ft_reponse(char *mot, char *hidden, char c);

void	ft_print_echaffau(int tries);
void	ft_print_mot(char *mot, char *hidden);
void    ft_print_used(char *used, char *mot);
void    ft_print_all(char *mot, char *hidden, char *used, int life);

#endif