/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:11:03 by clynderl          #+#    #+#             */
/*   Updated: 2019/10/28 16:51:00 by clynderl         ###   ########.fr       */
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

	int i = 0;
	while (i < ft_list_size(tetries))
	{
		printf("%s\n", tetries->data);
		tetries = tetries->next;
	}

	printf("\n%s",map->data);

	return (0);
}
