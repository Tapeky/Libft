/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:44:09 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 01:13:03 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst)
		return ;
	current = *lst;
	while (current && current->next)
		current = current->next;
	if (!current)
		*lst = new;
	else
		current->next = new;
}
