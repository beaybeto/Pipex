/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal_upper.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:43:04 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/17 14:44:58 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexadecimal_upper(unsigned int n)
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
	else if (n >= 10 && n <= 15)
	{
		ascii = n - 10 + 'A';
		write (1, &ascii, 1);
		counter += 1;
	}
	else
	{
		counter += ft_print_hexadecimal_upper(n / 16);
		counter += ft_print_hexadecimal_upper(n % 16);
	}
	return (counter);
}
