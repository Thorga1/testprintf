/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_fncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 12:00:07 by tordner           #+#    #+#             */
/*   Updated: 2024/05/29 13:14:54 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_char(char c, va_list ap)
{
	int	a;

	a = 0;
	if (c == '%')
	{
		ft_putchar('%');
		return (1);
	}
	else if (c == 'c')
	{
		a = va_arg(ap, int);
		ft_putchar(a);
		return (1);
	}
	else
		return (0);
}

int	check_str(char c, va_list ap)
{
	int		i;
	char	*str;
	char	*nul;

	nul = "(null)";
	i = 0;
	if (c == 's')
	{
		str = va_arg(ap, char *);
		if (str == NULL)
		{
			write(1, nul, 6);
			return (6);
		}
		while (str[i] != '\0')
		{
			ft_putchar(str[i]);
			i++;
		}
		return (i);
	}
	else
		return (0);
}

int	check_int(char c, va_list ap)
{
	int	x;
	int	count;

	count = 0;
	x = 0;
	if (c == 'i' || c == 'd')
	{
		x = va_arg(ap, int);
		count = ft_get_len(x);
		ft_putnbr(x);
		return (count);
	}
	else
		return (0);
}

int	check_unsigned(char c, va_list ap)
{
	unsigned int	x;
	int				count;

	count = 0;
	x = 0;
	if (c == 'u')
	{
		x = va_arg(ap, unsigned int);
		count = ft_get_unsigned(x);
		ft_putunsigned(x);
		return (count);
	}
	else
		return (0);
}
