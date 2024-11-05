/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:40:36 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/03 13:01:00 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final_str;
	size_t	i;
	size_t	j;

	if (start > ft_strlen(s))
		final_str = (char *)malloc(1);
	else if (len > ft_strlen(s) || (start + len) > ft_strlen(s))
		final_str = (char *)malloc(ft_strlen(s) + 1 - start);
	else
		final_str = (char *)malloc(len + 1);
	i = 0;
	j = 0;
	if (!final_str)
		return (NULL);
	while (s[i] && j < len)
	{
		if (i >= start)
		{
			final_str[j] = s[i];
			j++;
		}
		i++;
	}
	final_str[j] = '\0';
	return (final_str);
}
