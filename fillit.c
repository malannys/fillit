/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 17:53:04 by malannys          #+#    #+#             */
/*   Updated: 2019/05/16 18:03:00 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "fillit.h"
#include "libft/libft.h"

void	free_map(char** map, short num)
{
	short	i;

	i = 0;
	while (i < num)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	fill_map(t_tetri *t, char **map, short size, short num)
{
	short	i;
	short	j;

	while (--num >= 0)
	{
		i = -1;
		while (++i < t[num].width)
		{
			j = -1;
			while (++j < t[num].len)
			{
				if ((t[num].tetri >> (15 - (i + 4 * j))) & 1L)
					map[t[num].row + i][t[num].col + j] = t[num].id;
			}
		}
	}
}

void	display_map(t_tetri *t, short size, short num)
{
	char	**map;
	char	i;

	i = -1;
	if (!(map = (char**)malloc(sizeof(char*) * size)))
		return ;
	while (++i < size)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (size + 1))))
		{
			free_map(map, i);
			return ;
		}
		ft_memset(map[i], '.', size);
	}
	fill_map(t, map, size, num);
	i = -1;
	while (++i < size)
		ft_putendl(map[i]);
	free_map(map, size);
}

int		main(int ac, char **av)
{
	t_tetri	tetris[MAX_TETRI_NUM + 1]; // 26 tetriminos + 1
	short	map[16]; // map 16 * 16 (short = 2 bytes)
	int		fd;
	short	num; // number of tetriminos
	short	size; // size of the field

	if (ac != 2)
		ft_putendl("usage: ./fillit.out source_file");
	else if ((fd = open(av[1], O_RDONLY)) < 0)
		ft_putendl("error");
	else
	{
		ft_bzero(tetris, sizeof(t_tetri) * (MAX_TETRI_NUM + 1));
		if ((num = reader(fd, tetris)) <= 0)
		{
			ft_putendl("error");
			return (1);
		}
		ft_bzero(map, sizeof(short) * 16);
		size = filler(map, tetris, num);
		display_map(tetris, size, num);
	}
	return (0);
}
