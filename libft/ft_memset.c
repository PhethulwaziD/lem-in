/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:50:25 by pdonga            #+#    #+#             */
/*   Updated: 2019/06/25 14:22:57 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *dst, int ch, size_t len)
{
	unsigned char	*dest;
	unsigned char	c;
	int				i;

	i = 0;
	c = (unsigned char)ch;
	dest = dst;
	while (len > 0)
	{
		dest[i] = c;
		i++;
		len--;
	}
	return (dst);
}
