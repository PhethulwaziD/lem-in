/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 16:57:31 by pdonga            #+#    #+#             */
/*   Updated: 2019/07/19 16:55:07 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t i;
	size_t j;
	size_t length;

	length = 0;
	i = 0;
	if (nd[0] == '\0' || nd == hs)
		return ((char*)&hs[i]);
	length = ft_strlen(nd);
	while (i < len && hs[i])
	{
		j = 0;
		if (hs[i] == nd[j])
		{
			while (hs[i + j] == nd[j] && nd[j])
				j++;
			if (j == length && i + j < len)
				return ((char*)&hs[i]);
		}
		i++;
	}
	return (NULL);
}
