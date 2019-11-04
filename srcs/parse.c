/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:24:20 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/04 18:08:23 by clynderl         ###   ########.fr       */
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

int			ft_valid_tetri(char *buf, int k)
{
	int	i;
	int	hashes;
	int	touches;

	touches = 0;
	i = 0;
	hashes = 0;
	while (buf[i] != '\0')
	{
		if ((i + 1) % 5 == 0 && buf[i] != '\n')
			return (0);
		if ((i + 1) % 5 != 0 && buf[i] != '.' && buf[i] != '#')
			return (0);
		if (buf[i] == '#' && (buf[i] = 'A' + k))
		{
			touches +=
			(i + 5 <= 20 ? buf[i + 5] == '#' || ft_isalpha(buf[i + 5]) : 0) +
			(i - 5 >= 0 ? buf[i - 5] == '#' || ft_isalpha(buf[i - 5]) : 0) +
			(i + 1 <= 20 ? buf[i + 1] == '#' || ft_isalpha(buf[i + 1]) : 0) +
			(i - 1 >= 0 ? buf[i - 1] == '#' || ft_isalpha(buf[i - 1]) : 0);
			hashes++;
		}
		i++;
	}
	return (hashes == 4 && touches >= 6);
}

t_tetri		*ft_parse(int fd)
{
	t_tetri		*tetries;
	int			r;
	char		*buf;
	int			i;

	if (!(buf = ft_strnew(20)))
		return (NULL);
	r = 1;
	i = 0;
	tetries = NULL;
	while (r)
	{
		if ((r = read(fd, buf, 20)) < 0)
			return (NULL);
		buf[r] = '\0';
		if (r != 20 || !ft_valid_tetri(buf, i++))
			return (NULL);
		ft_list_push_back(&tetries, to_top_left(buf));
		if ((r = read(fd, buf, 1)) < 0)
			return (NULL);
		buf[r] = '\0';
		if (r == 1 && !ft_strequ(buf, "\n"))
			return (NULL);
	}
	return (i <= 26 ? (tetries) : (NULL));
}
