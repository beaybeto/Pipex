/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:05:19 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/17 12:07:34 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int n);
int	ft_print_unsigned_decimal(unsigned int n);
int	ft_print_hexadecimal_lower(unsigned int n);
int	ft_print_hexadecimal_upper(unsigned int n);
int	ft_print_direction(void *str);
int	ft_printf(char const *format, ...);

#endif