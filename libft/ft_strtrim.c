/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 14:51:29 by pdonga            #+#    #+#             */
/*   Updated: 2019/06/26 15:20:36 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_eschr(const char ch)
{
	if (ch == '\t' || ch == ' ' || ch == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		len;

	if (s)
	{
		len = ft_strlen(s) - 1;
		start = 0;
		while (ft_eschr(s[start]) == 1)
			start++;
		while (ft_eschr(s[len]) == 1 && len > start - 1)
			len--;
		len -= start;
		return (ft_strsub(s, start, len + 1));
	}
	return (NULL);
}
