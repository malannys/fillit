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

short	backtrack(short *map, t_tetri *t, short tetri_num, short size)
{
	if (t[tetri_num].id == 0)
		return (1);
	while (t[tetri_num].row < size - t[tetri_num].width)
	{
		t[tetri_num].col = 0;
		while (t[tetri_num].col < size - t[tetri_num].len)
		{
			if (//fit)
				{
					// fit the piece in the map
					if (backtrack(map, t, tetri_num + 1, size))
						return (1);
					// del the piece from the map
				}
			t[tetri_num].col++;
		}
		t[tetri_num].row++;
	}
	t[tetri_num].col = 0; // zeroizing the coordinates
	t[tetri_num].row = 0;
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
