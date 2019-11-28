/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:08:14 by plam              #+#    #+#             */
/*   Updated: 2019/11/27 16:55:03 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int		checker(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	erase_err(char **line)
{
	if (*line)
		free(*line);
	*line = NULL;
	return (-1);
}