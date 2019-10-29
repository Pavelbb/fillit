/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:24:45 by clynderl          #+#    #+#             */
/*   Updated: 2019/10/23 16:24:17 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri		*ft_create_elem(char *data)
{
	t_tetri	*elem;

	if (!(elem = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	elem->data = ft_strdup(data);
	elem->next = NULL;
	return (elem);
}

void		ft_list_push_back(t_tetri **begin_list, char *data)
{
	if (*begin_list)
	{
		if ((*begin_list)->next)
			ft_list_push_back(&((*begin_list)->next), data);
		else
			(*begin_list)->next = ft_create_elem(data);
	}
	else
		(*begin_list) = ft_create_elem(data);
}

int			ft_list_size(t_tetri *begin_list)
{
	if (!begin_list)
		return (0);
	else
		return (1 + (ft_list_size(begin_list->next)));
}
