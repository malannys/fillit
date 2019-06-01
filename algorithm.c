/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 15:31:19 by malannys          #+#    #+#             */
/*   Updated: 2019/05/23 15:31:59 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

short	check_tetri(short *map, t_tetri *t)
{
	return (!((*(map + t->row) & ((t->tetri & 61440) >> t->col))
			|| (*(map + t->row + 1) & ((t->tetri << 4 & 61440) >> t->col))
			|| (*(map + t->row + 2) & ((t->tetri << 8 & 61440) >> t->col))
			|| (*(map + t->row + 3) & ((t->tetri << 12 & 61440) >> t->col))));
}

void	fit_del_tetri(short *map, t_tetri *t)
{
	*(map + t->row) ^= (t->tetri & 61440) >> t->col;
	*(map + t->row + 1) ^= (t->tetri << 4 & 61440) >> t->col;
	*(map + t->row + 2) ^= (t->tetri << 8 & 61440) >> t->col;
	*(map + t->row + 3) ^= (t->tetri << 12 & 61440) >> t->col;
}

short	backtrack(short *map, t_tetri *t, short tetri_num, short size)
{
	if (t[tetri_num].id == 0)
		return (1);
	t[tetri_num].row = 0;
	while (t[tetri_num].row <= size - t[tetri_num].width)
	{
		t[tetri_num].col = 0;
		while (t[tetri_num].col <= size - t[tetri_num].len)
		{
			if (check_tetri(map, t + tetri_num))
				{
					fit_del_tetri(map, t + tetri_num);
					if (backtrack(map, t, tetri_num + 1, size))
						return (1);
					fit_del_tetri(map, t + tetri_num);
				}
			t[tetri_num].col++;
		}
		t[tetri_num].row++;
	}
	return (0);
}

short	filler(short *map, t_tetri *tetris, short num)
{
	short	size;

	size = 2;
	while (size * size < num * 4)
		size++;
	while (!(backtrack(map, tetris, 0, size)))
		size++;
	return (size);
}
