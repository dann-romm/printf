/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student-21.school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:25:46 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/08 18:18:28 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (lst == 0 || *lst == 0)
	{
		if (*lst == 0)
			*lst = new;
		return ;
	}
	node = *lst;
	while (node->next != 0)
		node = node->next;
	node->next = new;
}
