/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 13:06:14 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/09 14:51:01 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*shift_to_left(char *str)
{
	char	temp;
	int		i;
	int		j;

	i = -1;
	while (++i < 4)
	{
		temp = str[0 + (i * 5)];
		j = -1;
		while (++j < 3)
			str[j + (i * 5)] = str[j + (i * 5) + 1];
		str[3 + (i * 5)] = temp;
	}
	return (str);
}

char		*to_top_left(char *str)
{
	char	*new;
	int		i;
	int		j;

	if (!(new = ft_strnew(20)))
		return (NULL);
	i = -1;
	while (++i < 20)
		new[i] = (i + 1) % 5 == 0 ? '\n' : '.';
	i = 0;
	while (!(ft_isalpha(str[i])))
		i++;
	i = ((i + 1) / 5 * 5) - 1;
	j = -1;
	while (i < 20)
		new[j++] = str[i++];
	while (!(ft_isalpha(new[0]) || ft_isalpha(new[5])
			|| ft_isalpha(new[10]) || ft_isalpha(new[15])))
		new = shift_to_left(new);
	return (new);
}
