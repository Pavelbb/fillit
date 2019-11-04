/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:11:03 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/04 20:18:09 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char *argv[])
{
	int		fd;
	t_tetri	*tetries;
	t_map	*map;

	if (argc != 2)
	{
		ft_putendl("./fillit <filename>\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
	{
		ft_putendl("no such file\n");
		return (0);
	}
	if (!(tetries = ft_parse(fd)))
	{
		ft_putendl("error\n");
		return (0);
	}
	map = ft_solve(tetries);
	ft_putendl(map->data);
	return (0);
}
