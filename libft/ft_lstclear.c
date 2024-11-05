/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:01:02 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/04/30 17:14:40 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*clear;
	t_list	*temporal;

	clear = *lst;
	while (clear != NULL)
	{
		temporal = clear->next;
		del(clear->content);
		free(clear);
		clear = temporal;
	}
	*lst = NULL;
}
