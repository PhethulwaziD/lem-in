/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 11:05:37 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/27 14:31:37 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_places(int i)
{
	int		pwr;

	pwr = 0;
	if (i < 0)
		pwr++;
	while (i != 0)
	{
		i /= 10;
		pwr++;
	}
	return (pwr);
}

void		*ft_itoc(int i, int pw, char *ptr)
{
	int		j;

	j = 0;
	if (i)
	{
		if (i < 0)
		{
			ptr[j] = '-';
			j++;
			pw--;
			i *= -1;
		}
		while (pw != -1)
		{
			ptr[j] = (unsigned char)(i / ft_pow(10, pw) + 48);
			i %= ft_pow(10, pw);
			pw--;
			j++;
		}
		ptr[j] = '\0';
		return (ptr);
	}
	return (NULL);
}

void		*ft_itoa(int i)
{
	char	*ptr;
	int		pw;

	if (i == -2147483648)
		return (ft_strdup("-2147483648"));
	if (i == 0)
		return (ft_strdup("0"));
	ptr = (char*)malloc(sizeof(char) * (ft_places(i) + 1));
	if (ptr == NULL)
		return (NULL);
	pw = ft_places(i) - 1;
	return (ft_itoc(i, pw, ptr));
}
