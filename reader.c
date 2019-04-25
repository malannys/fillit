/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:38:30 by malannys          #+#    #+#             */
/*   Updated: 2019/04/07 15:38:32 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"


void    check_min_max(char *str, short *min_max)
{
    short   i;

    min_max[0] = 3;
    min_max[1] = 0;
    min_max[2] = 3;
    min_max[3] = 0;
    i = 0;
    while (i < 21)
    {
        if (str[i] == '#')
        {
            if (i % 5 < min_max[0])
                min_max[0] = i % 5;
            if (i % 5 > min_max[1])
                min_max[1] = i % 5;
            if (i / 5 < min_max[2])
                min_max[2] = i / 5;
            if (i / 5 > min_max[3])
                min_max[3] = i / 5;
        }
        i++;
    }
}

short   check_errors(char *str)
{
    short   i;
    short   j;

    i = 0;
    while (i < 21)
    {
        if (str[i] == '\n' && i % 5 != 4)
            return (1);
        if (str[i] == '#')
        {
            if (i % 5 == 3 && i / 5 == 3)
                return (0);
            if ()
    }
}

void    write_tetri(char *str, t_tetri *tetris)
{  
}

int     reader(int fd, t_tetri *tetris)
{
    char    str[21 + 1]; // tetrimino 4x5 [+ \n] + \0
    short    min_max[4];

    ft_bzero(str, 21);
    while(read(fd, str, 21) >= 20)
    {
        check_min_max(str, min_max);
        if (check_sides(str))
            return (1);
        write_tetri(str, tetris);
        ft_bzero(str, 21);
    }
}