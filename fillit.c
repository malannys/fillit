/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malannys <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:37:16 by malannys          #+#    #+#             */
/*   Updated: 2019/04/07 15:37:18 by malannys         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"
#include "libft/libft.h"

//print map

int main(int ac, char **av)
{
    int fd;

    if (ac != 2)
        ft_putendl("usage: ./fillit.out source_file");
    else if (fd = open(av[1], O_RDONLY)) < 0)
        ft_putendl("error");
    else
    {
        //hehe
    }
    return (0);
}
