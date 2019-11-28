/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:08:14 by plam              #+#    #+#             */
/*   Updated: 2019/11/27 16:50:44 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*sc;
	unsigned char	*dst;

	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	while (n)
	{
		*dst++ = *sc++;
		n--;
	}
}

int		ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strcjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	strsize;
	char	*dest;

	strsize = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(dest = (char *)malloc(sizeof(char) * (strsize + 1))))
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	if (s1)
		free(s1);
	return (dest);
}

t_list	*ft_lstnew_back(int fd, t_list **l1)
{
	t_list	*elem;
	t_list	*lst;

	lst = *l1;
	if (!(elem = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	elem->line[0] = '\0';
	elem->next = NULL;
	elem->fd = fd;
	if (*l1 == NULL)
		*l1 = elem;
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
		lst->next = elem;
	}
	return (elem);
}

t_list	*find_lst(int fd, t_list **l1)
{
	t_list	*lst;

	lst = *l1;
	while (lst != NULL)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (ft_lstnew_back(fd, l1));
}
