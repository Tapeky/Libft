/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:39:52 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 01:11:12 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*res;

	res = malloc (sizeof(t_list));
	if (!res)
		return (0);
	res->content = content;
	res->next = NULL;
	return (res);
}
