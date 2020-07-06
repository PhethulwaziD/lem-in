/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 14:46:53 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/03 11:07:49 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(char const *s, char ch)
{
	int				j;
	char			*str;
	char			**array;

	j = 0;
	if (!s || !(str = ft_trimch(s, ch)))
		return (NULL);
	if (!(array = (char**)malloc(sizeof(char*)
					* ft_wordcount((char *)str, ch) + 1)))
	{
		free(str);
		return (NULL);
	}
	array[ft_wordcount(str, ch)] = NULL;
	array = ft_split(str, ch, array, j);
	free(str);
	return (array);
}
