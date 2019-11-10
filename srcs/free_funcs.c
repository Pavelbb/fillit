/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 13:50:22 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/10 15:00:14 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_list_free(t_tetri *list)
{
	t_tetri *tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list->data);
		free(list);
		list = tmp;
	}
	free(tmp);
	return (0);
}

t_tetri	*ft_list_and_str_free(t_tetri *list, char *str)
{
	t_tetri *tmp;

	tmp = list;
	if (list != NULL)
	{
		while (list != NULL)
		{
			tmp = list->next;
			free(list->data);
			free(list);
			list = tmp;
		}
	}
	free(tmp);
	if (str != NULL)
		free(str);
	return (NULL);
}
