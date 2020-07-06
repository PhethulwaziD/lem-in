/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 09:21:54 by pdonga            #+#    #+#             */
/*   Updated: 2019/06/27 14:57:32 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_split(char *str, char ch, char **array, int j)
{
	size_t			len;
	unsigned int	start;
	int				i;

	i = 0;
	len = 0;
	start = len;
	while (str[i])
	{
		if (str[i] == ch && str[i])
			while (str[i] == ch)
				i++;
		start = i;
		if (str[i] != ch && str[i])
			len = 0;
		while (str[i] != ch && str[i])
		{
			i++;
			len++;
		}
		array[j] = ft_strsub(str, start, len);
		j++;
	}
	array[j] = NULL;
	return (array);
}
