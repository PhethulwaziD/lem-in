/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 13:56:45 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/27 14:13:39 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char *ptr;
	
	if (str != NULL)
	{
		if (!(ptr = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (NULL);
		ft_strcpy(ptr, str);
		return ((char*)ptr);
	}
	return (NULL);
}
