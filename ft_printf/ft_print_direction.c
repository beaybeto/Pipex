/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_direction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 13:00:56 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/06/28 12:08:17 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_print_hexadecimal(unsigned long n)
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
		ascii = n - 10 + 'a';
		write(1, &ascii, 1);
		counter += 1;
	}
	else
	{
		counter += ft_print_hexadecimal(n / 16);
		counter += ft_print_hexadecimal(n % 16);
	}
	return (counter);
}

int	ft_print_direction(void *str)
{
	unsigned long	adress;
	int				counter;

	if (str == NULL)
		return (write(1, "(nil)", 5));
	counter = 0;
	adress = (unsigned long)str;
	write(1, "0x", 2);
	counter += 2;
	counter += ft_print_hexadecimal(adress);
	return (counter);
}
