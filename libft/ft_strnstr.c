/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:41:33 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/03 12:45:15 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;
	char	*substr;

	str = (char *) haystack;
	substr = (char *) needle;
	i = 0;
	if (!*substr)
		return (str);
	while (str[i] != '\0' && i < len)
	{
		j = 0;
		while (substr[j] != '\0' && (str[i + j] == substr[j])
			&& ((i + j) < len))
		{
			j++;
		}
		if (substr[j] == '\0')
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}
