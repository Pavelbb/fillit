/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clynderl <clynderl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 10:07:37 by clynderl          #+#    #+#             */
/*   Updated: 2019/11/10 13:46:29 by clynderl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

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

t_tetri				*ft_parse(int fd, int r);
int					ft_list_free(t_tetri *list);
t_tetri				*ft_list_and_str_free(t_tetri *list, char *str);
t_tetri				*ft_create_elem(char *data);
void				ft_list_push_back(t_tetri **begin_list, char *data);
int					ft_list_size(t_tetri *begin_list);
t_map				*ft_solve(t_tetri *tetries);
char				*to_top_left(char *str);

#endif
