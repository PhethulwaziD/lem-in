/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:07:21 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/21 15:04:20 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_line(const int fd, char **str)
{
	int			ret;
	char		*buff;
	char		*tmp;

	buff = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (*str == NULL)
			*str = ft_strnew(0);
		tmp = *str;
		*str = ft_strjoin(*str, buff);
		free(tmp);
		if (ft_strchr(*str, '\n'))
			break ;
	}
	free(buff);
	if (ret == 0 || ret < 0)
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		*end;
	static char	*str[MAX_FD];
	char		*hold;
	int			ret;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	ret = get_line(fd, &str[fd]);
	if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	end = ft_strchr(str[fd], '\n');
	*line = ft_strsub(str[fd], 0, (ft_strlen(str[fd]) - ft_strlen(end)));
	hold = str[fd];
	str[fd] = ft_strsub(end, 1, ft_strlen(end) - 1);
	free(hold);
	return (1);
}