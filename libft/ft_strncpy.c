/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:29:53 by pdonga            #+#    #+#             */
/*   Updated: 2019/07/19 22:37:48 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t i)
{
	size_t len;

	len = 0;
	while (len < i && src[len])
	{
		dst[len] = src[len];
		len++;
	}
	while (len < i)
		dst[len++] = '\0';
	return (dst);
}
