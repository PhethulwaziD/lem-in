/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trimch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 08:55:42 by pdonga            #+#    #+#             */
/*   Updated: 2019/07/19 16:35:38 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_trimch(const char *s, const char ch)
{
	int		start;
	int		len;

	if (s)
	{
		len = ft_strlen(s) - 1;
		start = 0;
		while (s[start] == ch)
			start++;
		while (s[len] == ch && len > start - 1)
			len--;
		len -= start;
		return (ft_strsub(s, start, len + 1));
	}
	return (NULL);
}
