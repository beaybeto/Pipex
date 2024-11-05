/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:08:53 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/03 12:45:07 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str_1;
	unsigned char	*str_2;

	i = 0;
	str_1 = (unsigned char *)s1;
	str_2 = (unsigned char *)s2;
	while (i < n && (str_1[i] != '\0' || str_2[i] != '\0'))
	{
		if (str_1[i] != str_2[i])
		{
			return (str_1[i] - str_2[i]);
		}
		i++;
	}
	return (0);
}
