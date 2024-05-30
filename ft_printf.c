/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 19:16:31 by tordner           #+#    #+#             */
/*   Updated: 2024/05/30 11:57:44 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	create_tab(int (*convert[5])(char, va_list))
{
	convert[0] = &check_char;
	convert[1] = &check_str;
	convert[2] = &check_int;
	convert[3] = &check_unsigned;
	convert[4] = &check_hexa;
	convert[5] = &check_ptr;
	return ;
}

int	parse_buff(const char *format, va_list ap)
{
	int		i;
	int		j;
	int		count;
	t_conv	convert[5];

	create_tab(convert);
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
			count += write(1, &format[i], 1);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (format == 0)
		return (-1);
	count = 0;
	va_start(ap, format);
	count = parse_buff(format, ap);
	va_end(ap);
	return (count);
}
