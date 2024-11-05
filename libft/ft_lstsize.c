/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:24:01 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/04/30 12:35:34 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*len;
	int		n;

	n = 0;
	len = lst;
	while (len != NULL)
	{
		n++;
		len = len->next;
	}
	return (n);
}
