/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:03:15 by tordner           #+#    #+#             */
/*   Updated: 2024/05/29 14:21:50 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_ptrlen(unsigned long long n)
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

void	put_ptr(unsigned long long n)
{
	if (n >= 16)
	{
		put_ptr(n / 16);
		put_ptr(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

int	check_ptr(char c, va_list ap)
{
	unsigned long long	x;
	int					count;

	count = 0;
	x = 0;
	if (c == 'p')
	{
		x = va_arg(ap, unsigned long long);
		if (x == 0)
		{	
			count += write(1, "(nil)", 5);
			return (count);
		}
		count = ft_get_ptrlen(x);
		count += write(1, "0x", 2);
		put_ptr(x);
		return (count);
	}
	else
		return (0);
}
