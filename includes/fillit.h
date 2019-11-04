/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:07:37 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/04 18:09:09 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h> //
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef	struct		s_tetri
{
	char			*data;
	int				pos;
	struct s_tetri	*next;
}					t_tetri;

typedef	struct		s_map
{
	char			*data;
	int				size;
	int				area;
}					t_map;

t_tetri				*ft_parse(int fd);
t_tetri				*ft_create_elem(char *data);
void				ft_list_push_back(t_tetri **begin_list, char *data);
int					ft_list_size(t_tetri *begin_list);
t_map				*ft_solve(t_tetri *tetries);

#endif
