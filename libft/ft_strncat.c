/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 09:59:34 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/03 13:02:55 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	i = ft_strlen(dst);
	while (n < len && src[n])
	{
		dst[i] = src[n];
		n++;
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
