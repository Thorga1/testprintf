/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:36:29 by tordner           #+#    #+#             */
/*   Updated: 2024/05/29 14:08:23 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef int	(*t_conv)(char, va_list);

void	put_ptr(unsigned long long n);
int		ft_get_ptrlen(unsigned long long n);
int		check_ptr(char c, va_list ap);
int		ft_get_hexalen(unsigned int n);
void	put_hexa(unsigned int n, const char c);
int		check_hexa(char c, va_list ap);
void	ft_putunsigned(unsigned int n);
int		ft_get_unsigned(unsigned int n);
int		ft_get_len(int n);
int		check_char(char c, va_list ap);
int		check_str(char c, va_list ap);
int		check_int(char c, va_list ap);
int		check_unsigned(char c, va_list ap);
int		ft_strlen(char *str);
int		ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int		ft_printf(const char *format, ...);

#endif
