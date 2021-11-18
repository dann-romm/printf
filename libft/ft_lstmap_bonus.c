/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doalbaco <doalbaco@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:25:59 by doalbaco          #+#    #+#             */
/*   Updated: 2021/10/13 02:49:35 by doalbaco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*node;

	if (lst == 0 || f == 0 || del == 0)
		return (0);
	list = ft_lstnew((*f)(lst->content));
	node = list;
	lst = lst->next;
	while (node && lst)
	{
		node->next = ft_lstnew((*f)(lst->content));
		node = node->next;
		if (node == 0)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		lst = lst->next;
	}
	return (list);
}
