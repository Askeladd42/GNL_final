/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plam <plam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 10:07:36 by plam              #+#    #+#             */
/*   Updated: 2019/11/28 14:04:19 by plam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(int fd, char **line)
{
	static t_list	lst;
	int				err;

	*line = NULL;
	if (!line || fd < 0)
		return (-1);
	if (lst.line[0] != '\0')
		if (!(*line = ft_strcjoin(*line, lst.line)))
			return (erase_err(line));
	while (checker(lst.line) == -1)
	{
		if ((err = read(fd, lst.line, BUFFER_SIZE)) == -1)
			return (erase_err(line));
		lst.line[err] = '\0';
		if (!(*line = ft_strcjoin(*line, lst.line)))
			return (erase_err(line));
		if (err == 0)
			return (0);
	}
	ft_memmove(lst.line, lst.line + checker(lst.line) + 1, \
		ft_strlen(lst.line + checker(lst.line) + 1) + 1);
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;
	int		ret;

	i = 0;
	line = NULL;
	fd = (ac == 1) ? 1 : open(av[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) == 1)
	{	
		printf("Ret:%d \033[1;31m%d\033[0m\t%s\n", ret, i, line);
		free(line);
		i++;
	}
	free(line);
	close(fd);
	//while (1);
	return (0);
}