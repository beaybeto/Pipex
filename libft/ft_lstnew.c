/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:31:17 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/05/03 10:53:57 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node_creation;

	node_creation = malloc(sizeof(t_list));
	if (!node_creation)
		return (NULL);
	node_creation->content = content;
	node_creation->next = NULL;
	return (node_creation);
}
