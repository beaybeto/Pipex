/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:01:28 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/06/28 12:10:31 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_values(char const *format, int i, va_list vargs)
{
	int	sum;

	sum = 0;
	if (format[i + 1] == 'c')
		sum += ft_putchar(va_arg(vargs, int));
	else if (format[i + 1] == '%')
		sum += ft_putchar('%');
	else if (format[i + 1] == 's')
		sum += ft_putstr(va_arg(vargs, char *));
	else if (format[i + 1] == 'i' || format[i + 1] == 'd')
		sum += ft_putnbr(va_arg(vargs, int));
	else if (format[i + 1] == 'p')
		sum += ft_print_direction(va_arg(vargs, void *));
	else if (format[i + 1] == 'u')
		sum += ft_print_unsigned_decimal(va_arg(vargs, unsigned int));
	else if (format[i + 1] == 'x')
		sum += ft_print_hexadecimal_lower(va_arg(vargs, unsigned int));
	else if (format[i + 1] == 'X')
		sum += ft_print_hexadecimal_upper(va_arg(vargs, unsigned int));
	return (sum);
}

int	ft_printf(char const *format, ...)
{
	int		sum;
	int		i;
	va_list	vargs;

	va_start(vargs, format);
	i = 0;
	sum = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			sum += ft_putchar(format[i]);
		}
		else
		{
			sum += ft_values(format, i, vargs);
			i++;
		}
		i++;
	}
	va_end(vargs);
	return (sum);
}
/*#include <stdio.h>
int	main(void)
{
	int w = -8510;
	int x;
	int y;
	void *str = "para comprobar que funciona mi printf";
	void *str = NULL;
	int y;
	int x;
	x = ft_print_direction(str);
	ft_printf("valor de mi print_direction%p\n", str);
	printf("valor del printf original%p", str);
	x = ft_printf("estoy imprimiendo un nº %d y una str %s", w, str);
	ft_printf("\n");
	y = printf("estoy imprimiendo un nº %d y una str %s", w, str);
	printf("\nla longitud de mi funcion es:%d y la de la original es:%d", x, y);
	return (0);
}*/