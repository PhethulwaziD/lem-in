/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 09:34:26 by pdonga            #+#    #+#             */
/*   Updated: 2019/06/19 16:54:22 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void *ptr;

	if (!size)
		return (NULL);
	if (!(ptr = (unsigned char*)malloc(size)))
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}
