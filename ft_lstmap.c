/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 17:29:05 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 11:47:05 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*current;

	if (!lst)
		return (0);
	res = malloc(sizeof(t_list));
	if (!res)
		return (0);
	res -> content = f(lst->content);
	lst = lst->next;
	current = res;
	while (lst)
	{
		current->next = malloc(sizeof(t_list));
		if (!current->next)
		{
			ft_lstclear(&res, del);
			return (0);
		}
		current = current->next;
		current->content = f(lst->content);
		lst = lst->next;
	}
	current->next = NULL;
	return (res);
}
