/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:27:03 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/02 15:35:21 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill(t_tetri *tetri, t_map *map, int pos)
{
	int i;

	i = -1;
	while((tetri->data)[++i])
	{
		if (ft_isalpha((tetri->data)[i]))
			(map->data)[pos] = (tetri->data)[i];
		pos += 1 + ((tetri->data)[i] == '\n') * (map->size - 4);
	}
}

int		ft_is_placeable(t_tetri *tetri, t_map *map, int pos)
{
	int	i;

	i = -1;
	while ((tetri->data)[++i])
	{
		if (ft_isalpha((tetri->data)[i]))
		{
			if ((pos < 0 || pos >= map->area) || (pos >= 0 && pos < map->area && ft_isalpha((map->data)[pos]))
			 || (pos >= 0 && pos < map->area && (map->data)[pos] == '\n'))
			 	return (0);
		}
		if (pos >= 0 && pos < map->area && (map->data)[pos] == '\n' && ft_isalpha((tetri->data)[i]))
			return (0);
		pos += 1 + ((tetri->data)[i] == '\n') * (map->size - 4);
	}
	return (1);
}

int		ft_backtracing(t_tetri *tetries, t_map *map)
{
	t_tetri *tetri;
	int i;
	int pos;

	pos = 0;
	i = 0;
	tetri = tetries;
	while (i < 2)
	{
		while (!ft_is_placeable(tetri, map, pos))
			pos++;
		ft_fill(tetri, map, pos);
		tetri = tetri->next;
		i++;
	}
	return (1);
}

t_map	*ft_solve(t_tetri *tetries)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->size = ft_sqrt((ft_list_size(tetries) * 4));
	map->data = NULL;
	while (map->size <= 104)
	{
		map->area = (map->size * (map->size + 1));
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
