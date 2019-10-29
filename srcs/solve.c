/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:27:03 by clynderl          #+#    #+#             */
/*   Updated: 2019/10/28 16:52:31 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_backtracing(t_tetri *tetries, t_map *map)
{
	(void)map;
	(void)tetries;
	return (1);
}

t_map		*ft_solve(t_tetri *tetries)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->size = ft_sqrt((ft_list_size(tetries) * 4));
	map->data = NULL;
	while (map->size <= 104)
	{
		map->data = ft_strnew(map->size * (map->size + 1));
		i = 0;
		while (i < (map->size * (map->size + 1)))
		{
			map->data[i] = (i - map->size) % (map->size + 1) == 0 ? '\n' : '.';
			i++;
		}
		map->data[i] = '\0';
		if (ft_backtracing(tetries, map))
			return (map);
		map->size++;
	}
	return (NULL);
}
