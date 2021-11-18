/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:26:10 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/13 02:48:38 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*list;

	if (lst == 0 || del == 0)
		return ;
	list = *lst;
	while (list != 0)
	{
		node = list->next;
		ft_lstdelone(list, del);
		list = node;
	}
	*lst = 0;
}
