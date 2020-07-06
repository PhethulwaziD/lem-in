/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:26:34 by pdonga            #+#    #+#             */
/*   Updated: 2019/09/03 11:08:47 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *str, const char *str1)
{
	unsigned int	i;

	i = 0;
	if (!str[i] || !str1[i])
		return (-1);
	while ((str[i] && str1[i]))
	{
		if (str[i] == str1[i])
			i++;
		else
			break ;
	}
	return ((unsigned char)str[i] - (unsigned char)str1[i]);
}
