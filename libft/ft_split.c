/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:26:03 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/11/26 14:11:01 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	free_split(char **split)
{
	size_t	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
		free(split[i++]);
	free(split);
}

char	**ft_split(char const *s, char c)
{
	char	**new_string;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (NULL);
	new_string = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!new_string)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c && ++len)
				++s;
			new_string[i++] = ft_substr(s - len, 0, len);
			if (!new_string[i - 1])
				return (free_split(new_string), NULL);
		}
		else
			++s;
	}
	return (new_string[i] = 0, new_string);
}
