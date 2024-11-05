/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:10:41 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/02 16:24:17 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*origen;
	size_t	i;

	dest = (char *)dst;
	origen = (char *)src;
	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i > 0)
		{
			i--;
			dest[i] = origen[i];
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}
