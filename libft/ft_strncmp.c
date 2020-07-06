/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:01:52 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/03 13:02:32 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
		return (0);
	if (len > 1)
		while (i < len - 1 && (s1[i] && s2[i]))
		{
			if (s1[i] == s2[i])
				i++;
			else
				break ;
		}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
