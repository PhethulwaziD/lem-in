/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 08:08:04 by pdonga            #+#    #+#             */
/*   Updated: 2019/07/19 16:25:57 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_wordcount(char *str, const char ch)
{
	int i;
	int words;

	words = 1;
	if (!str || !str[0])
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] != ch && str[i])
		{
			while (str[i] == ch && str[i])
				i++;
			words++;
		}
		i++;
	}
	return (words);
}
