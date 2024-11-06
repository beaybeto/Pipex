/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:51:15 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/17 14:41:47 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned_decimal(unsigned int n)
{
	char	ascii;
	int		counter;

	counter = 0;
	if (n <= 9)
	{
		ascii = n + '0';
		write (1, &ascii, 1);
		counter += 1;
	}
	else
	{
		counter += ft_print_unsigned_decimal (n / 10);
		counter += ft_print_unsigned_decimal (n % 10);
	}
	return (counter);
}
