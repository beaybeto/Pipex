/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:32:02 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/03 12:41:54 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			str[12];
	int				i;
	int				sign;
	unsigned int	nb;

	sign = 1;
	i = 11;
	str[i--] = '\0';
	nb = n;
	if (n == 0)
		return (str[i] = '0', ft_strdup(&str[i]));
	if (n < 0)
	{
		sign = -1;
		nb = -n;
	}
	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (sign == -1)
		str[i--] = '-';
	return (ft_strdup(&str[i + 1]));
}
