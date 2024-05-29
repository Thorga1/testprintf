/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_hexa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:18:08 by tordner           #+#    #+#             */
/*   Updated: 2024/05/29 14:04:07 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_hexalen(unsigned int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		res++;
	}
	return (res);
}

void	put_hexa(unsigned int n, const char c)
{
	if (n >= 16)
	{
		put_hexa(n / 16, c);
		put_hexa(n % 16, c);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (c == 'x')
				ft_putchar(n - 10 + 'a');
			else if (c == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	check_hexa(char c, va_list ap)
{
	unsigned int	x;
	int				count;

	count = 0;
	x = 0;
	if (c == 'x' || c == 'X')
	{
		x = va_arg(ap, unsigned int);
		count = ft_get_hexalen(x);
		put_hexa(x, c);
		return (count);
	}
	else
		return (0);
}
