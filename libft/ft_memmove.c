/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 00:24:35 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/03 11:06:28 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*to;
	char	*from;
	size_t	i;

	to = (char *)dst;
	from = (char *)src;
	i = 0;
	if (src == dst)
		return (dst);
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			to[i] = from[i];
	}
	else
	{
		while (len > i)
		{
			to[i] = from[i];
			i++;
		}
	}
	return (dst);
}
