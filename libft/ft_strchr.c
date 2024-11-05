/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 12:10:59 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/02 18:24:34 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	char	*array;
	int		i;

	a = (int)c;
	array = (char *) s;
	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] == a)
		{
			return (&array[i]);
		}
		i++;
	}
	if (a == '\0')
	{
		return (&array[i]);
	}
	return (NULL);
}
