/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdonga <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:02:57 by pdonga            #+#    #+#             */
/*   Updated: 2019/08/14 11:18:31 by pdonga           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_place(int i)
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

void		ft_putnbr_fd(int i, int fd)
{
	int		pw;

	if (fd >= 0)
	{
		if (i == -2147483648)
			ft_putstr_fd("-2147483648", fd);
		if (i == 0)
			ft_putstr_fd("0", fd);
		pw = ft_place(i) - 1;
		if (i && i != 0 && i != -2147483648)
		{
			if (i < 0)
			{
				ft_putchar_fd('-', fd);
				pw--;
				i *= -1;
			}
			while (pw != -1)
			{
				ft_putchar_fd((unsigned char)(i / ft_pow(10, pw) + 48), fd);
				i %= ft_pow(10, pw);
				pw--;
			}
		}
	}
}
