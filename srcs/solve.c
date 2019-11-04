/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:27:03 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/04 20:35:28 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_fill(t_tetri *tetri, t_map *map, int pos, int fill)
{
	int i;

	i = -1;
	while ((tetri->data)[++i])
	{
		if (ft_isalpha((tetri->data)[i]))
			(map->data)[pos] = fill == 1 ? (tetri->data)[i] : '.';
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
			if ((pos < 0 || pos >= map->area) ||
			(pos >= 0 && pos < map->area && ft_isalpha((map->data)[pos]))
			|| (pos >= 0 && pos < map->area && (map->data)[pos] == '\n'))
				return (0);
		if (pos >= 0 && pos < map->area &&
		(map->data)[pos] == '\n' && ft_isalpha((tetri->data)[i]))
			return (0);
		pos += 1 + ((tetri->data)[i] == '\n') * (map->size - 4);
	}
	return (1);
}

int		ft_backtracking(t_tetri *tetries, t_map *map, int pos)
{
	t_tetri *tetri;
	int		i;
	int		ls;

	ls = ft_list_size(tetries);
	tetri = tetries;
	i = 0;
	while (i < ls)
	{
		if (tetri->pos == -1)
			break ;
		tetri = tetri->next;
		i++;
	}
	if (i == ls)
		return (1);
	while (pos < map->area)
	{
		while (tetri && (tetri->pos > 0))
			tetri = tetri->next;
		if (ft_is_placeable(tetri, map, pos))
		{
			ft_fill(tetri, map, pos, 1);
			tetri->pos = pos;
			if (ft_backtracking(tetri, map, 0))
				return (1);
			ft_fill(tetri, map, pos, 0);
			tetri->pos = -1;
		}
		pos++;
	}
	return (0);
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
		if (ft_backtracking(tetries, map, 0))
			return (map);
		map->size++;
	}
	return (NULL);
}
