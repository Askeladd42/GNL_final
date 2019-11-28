/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:08:41 by plam              #+#    #+#             */
/*   Updated: 2019/11/27 16:51:05 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_list
{
	int				fd;
	char			line[BUFFER_SIZE + 1];
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew_back(int fd, t_list **l1);
t_list			*find_lst(int fd, t_list **l1);
void			ft_memmove(void *dest, const void *src, size_t n);
int				ft_strlen(char *str);
char			*ft_strcjoin(char *s1, char *s2);
int				checker(char *line);
int				get_next_line(int fd, char **line);

#endif
