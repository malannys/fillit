/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:38:30 by malannys          #+#    #+#             */
/*   Updated: 2019/05/16 18:02:32 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

/*
** [0] - min_x, [1] - max_x, [2] - min_y, [3] - max_y
*/
void	check_min_max(char *str, short *min_max)
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

short	check_sides(char* s, short *min_max)
{
    char    i;
    char    sides;
    char    sharps;
	
	sharps = 0;
	sides = 0;
	i = min_max[0] + min_max[2] * 5 - 1;
	while (++i < min_max[1] + min_max[3] * 5)
	{
		if (s[i] == '#')
		{
			sharps++;
			if (s[i + 1] == '#')
				sides++;
			else if (i < 14 && s[i + 5] == '#')
				sides++;
		}
	}
	return (sharps == 4 && sides == 3 ? 1 : 0);
}

short   check_errors(char *str, short *min_max, short rd)
{
	short   i;
	
	i = 0;
	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (1);
	while (i < 20)
	{
		if (i % 5 != 4 && str[i] != '#' && str[i] != '.')
			return (1);
		i++;
	}
	if (rd == 21 && str[20] != '\n')
		return (1);
	check_min_max(str, min_max);
	if (check_sides(str, min_max))
		return (1);
	return (0);
}

void	write_tetri(char *str, short num, short *min_max, t_tetri *tetris)
{  
}

int		reader(int fd, t_tetri *tetris)
{
	char    str[22]; // tetrimino 4 * 5 [+ \n] + \0
	short   min_max[4];
	short   is_last;
	short   rd;
	short	num;
	
	num = 0;
	ft_bzero(str, 22);
	while((rd = read(fd, str, 21)) >= 20)
	{
		if (++num > MAX_TETRI_NUM || check_errors(str, min_max, rd))
			return (1);
		write_tetri(str, num, min_max, tetris);
		ft_bzero(str, 22);
	}
	if (rd != 0)
		return (1);
	return (0);
}
