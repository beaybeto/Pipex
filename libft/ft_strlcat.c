/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 11:14:59 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/02 18:21:41 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	j = ft_strlen(dst);
	if (dstsize == 0 || dest_len >= dstsize)
		return (src_len + dstsize);
	else
	{
		while (src[i] != '\0' && i < (dstsize - dest_len - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
	}
	dst[j] = '\0';
	return (dest_len + src_len);
}
