/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:49:43 by malannys          #+#    #+#             */
/*   Updated: 2019/04/07 16:49:45 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_TETRI_NUM 26
# include "libft/libft.h"

typedef struct	s_tetri
{
	char	id;
	short	tetri; // 16 bit
	short	width;
	short	len;
	short	row; // y coordinate of the left corner of the tetrimino
	short	col; // x coordinate of the left corner of the tetrimino
}				t_tetri;

short	reader(int fd, t_tetri *tetris);
t_tetri	write_tetri(char *str, short num, short *min_max, t_tetri *tetris);
short	check_errors(char *str, short rd);
short	check_sides(char *s);
void	check_min_max(char *str, short *min_max);
short	display_map(t_tetri *t, short size, short num);
void	fill_map(t_tetri *t, char **map, short size, short num);
void	free_map(char** map, short num);
short	filler(short *map, t_tetri *tetris, short num);
short	backtrack(short* map, t_tetri* t, short tetri_num, short size);

#endif
