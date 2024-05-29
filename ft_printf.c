/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:16:31 by tordner           #+#    #+#             */
/*   Updated: 2024/05/29 02:03:08 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_char(char c, va_list ap)
{
	char	a;

	a = 'a';
	if (c == 'c')
	{
		a = va_arg(ap, char);
		ft_putchar(a);
		return (1);
	}
	else
		return (0);
}

int    check_str(char c, va_list ap)
{
        int     i;
	char	*str;

	i = 0;
	if (c == 's')
	{
		str = va_arg(ap, char*);
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
	if (c == 'i')
	{
//		count = ft_strlen(str);
		x = va_arg(ap, int);
		ft_putnbr(x);
		return (count);
	}
	else
		return (0);
}

int	parse_buff(const char *format, va_list ap)
{
	int	i;
	int	j;
	int	count;
	conv	convert[] = { check_char, check_str, check_int };
	
	i = 0;
	j = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			while (j < 3)
			{
				count += convert[j](format[i + 1], ap);
				j++;
			}
			j = 0;
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	count;

	count = 0;
	va_start(ap, format);
	count = parse_buff(format, ap);
	va_end(ap);
	return (count);
}

int	main()
{
	ft_printf("My favourite %s color %c is spring.\n", "hey", 'c');
}
