/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tordner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 15:36:29 by tordner           #+#    #+#             */
/*   Updated: 2024/05/28 21:14:45 by tordner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef	int (*conv)(char, va_list);

int	ft_strlen(char *str);
int	ft_atoi(const char *str);
void	ft_putnbr(int n);
void	ft_putchar(char c);
int	ft_printf(const char *format, ...);

#endif
