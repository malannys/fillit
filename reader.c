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
	short	i;

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

short	check_sides(char *s)
{
	char	i;
	char	sides;
	char	sharps;

	sharps = 0;
	sides = 0;
	i = -1;
	while (++i < 20)
	{
		if (s[i] == '#')
		{
			sharps++;
			if (i - 1 >= 0 && s[i - 1] == '#')
				sides++;
			if (i - 5 >= 0 && s[i - 5] == '#')
				sides++;
			if (i + 1 < 20 && s[i + 1] == '#')
				sides++;
			if (i + 5 < 20 && s[i + 5] == '#')
				sides++;
		}
	}
	return (sharps != 4 || sides < 6);
}

short	check_errors(char *str, short rd)
{
	short	i;

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
	if (check_sides(str))
		return (1);
	return (0);
}

t_tetri		write_tetri(char *str, short num, short *min_max, t_tetri *tetris)
{
	t_tetri	tetri;
	short	i;
	short	j;

	i = min_max[0] - 1;
	tetri.tetri = 0;
	tetri.id = 'A' + num - 1;
	tetri.len = min_max[1] - min_max[0] + 1;
	tetri.width = min_max[3] - min_max[2] + 1;
	while (++i <= min_max[1])
	{
		j = min_max[2] - 1;
		while (++j <= min_max[3])
		{
			if (str[i + 5 * j] == '#')
				tetri.tetri |= 1L << (15 - i - 4 * j);
		}
	}
	return (tetri);
}

short	reader(int fd, t_tetri *tetris)
{
	char	str[21]; // tetrimino 4 * 5 [+ \n]
	short	min_max[4];
	short	not_last;
	short	rd;
	short	num;

	num = 0;
	str[20] = '\0';
	while ((rd = read(fd, str, 21)) >= 20)
	{
		not_last = rd == 21 ? 1 : 0;
		if (++num > MAX_TETRI_NUM || check_errors(str, rd))
			return (-1);
		check_min_max(str, min_max);
		tetris[num - 1] = write_tetri(str, num, min_max, tetris);
		str[20] = '\0';
	}
	if (rd != 0 || not_last == 1)
		return (-1);
	return (num);
}
