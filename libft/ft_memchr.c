/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:01:33 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/03 12:43:24 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*ptr;
	size_t			i;

	a = (char)c;
	ptr = (unsigned char *)s;
	i = 0;
	if (n == 0)
		return (NULL);
	while (ptr != NULL && i < n - 1)
	{
		if (ptr[i] == a)
		{
			return (&ptr[i]);
		}
		i++;
	}
	if (ptr[i] != a)
	{
		return (NULL);
	}
	return (&ptr[i]);
}
