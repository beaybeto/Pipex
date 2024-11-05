/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:30:59 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/03 12:44:46 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*memory;

	i = 0;
	j = 0;
	memory = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!memory)
		return (NULL);
	while (s1[i] != '\0')
	{
		memory[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		memory[i] = s2[j];
		i++;
		j++;
	}
	memory[i] = '\0';
	return (memory);
}
