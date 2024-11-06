/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:43:22 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/17 14:42:58 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	char	ascii;
	int		counter;

	counter = 0;
	if (n == -2147483648)
		return (write (1, "-2147483648", 11));
	else if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		counter = 1;
	}
	if (n >= 0 && n <= 9)
	{
		ascii = n + '0';
		return (counter + write (1, &ascii, 1));
	}
	else
	{
		counter += ft_putnbr (n / 10);
		counter += ft_putnbr (n % 10);
	}
	return (counter);
}
