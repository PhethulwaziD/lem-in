/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 10:39:45 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/27 14:32:00 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	ans;

	neg = 1;
	ans = 0;
	i = 0;
	while (ft_escape(str[i]) == 1 && str[i])
		i++;
	if (str[i] == '-' && str[i])
		neg = -1;
	if ((str[i] == '-' || str[i] == '+') && str[i])
		i++;
	while (ft_isdigit(str[i]) != 0 && str[i])
	{
		ans = ans * 10 + (str[i] - 48);
		i++;
	}
	return (ans * neg);
}
