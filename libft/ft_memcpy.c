/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:32:53 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/02 16:00:29 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*origen;
	size_t	i;

	dest = (char *)dst;
	origen = (char *)src;
	i = 0;
	if (!dst && !src)
		return (dst);
	while (i < n)
	{
		dest[i] = origen[i];
		i++;
	}
	return (dst);
}
