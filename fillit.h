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

#include "libft/libft.h"

typedef struct  s_tetri
{
    char    id;
    short   tetri; //min 16 bit
    short    width;
    short     len;
}               t_tetri;

#endif