/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:16:31 by tordner           #+#    #+#             */
/*   Updated: 2024/05/29 14:11:26 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_buff(const char *format, va_list ap)
{
	int		i;
	int		j;
	int		count;
	t_conv	convert[] = { check_char, check_str, check_int, check_unsigned, check_hexa, check_ptr };

	i = 0;
	j = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			while (j < 6)
				count += convert[j++](format[i + 1], ap);
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
	int		count;

	count = 0;
	va_start(ap, format);
	count = parse_buff(format, ap);
	va_end(ap);
	return (count);
}
