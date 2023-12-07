/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:35:15 by tomoron           #+#    #+#             */
/*   Updated: 2023/12/04 09:58:25 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*ft_strncpy(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < (n))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

t_result	*ft_lstadd_bak(t_result **lst, char *buffer, int n, int start)
{
	t_result	*current;

	if (!lst)
		return (0);
	current = *lst;
	while (current && current->next)
		current = current->next;
	if (!current)
	{
		*lst = malloc(sizeof(t_result));
		if (!*lst)
			return (0);
		ft_strncpy((*lst)->part, buffer + start, n - start);
		(*lst)->next = 0;
	}
	else
	{
		current->next = malloc(sizeof(t_result));
		if (!current->next)
			return (0);
		ft_strncpy(current->next->part, buffer + start, n - start);
		current->next->next = 0;
	}
	return (*lst);
}

char	*ft_lstclr(t_result **lst, t_buffer **buf_srt, t_buffer *buffer)
{
	t_result	*next;

	if (lst)
	{
		while (*lst)
		{
			next = (*lst)->next;
			free(*lst);
			*lst = next;
		}
	}
	if (buf_srt && buffer && (buffer->rd_l == 0 || buffer->i == buffer->rd_l
			|| buffer->rd_l == -1))
		ft_lstdelon(buffer, buf_srt);
	return (0);
}

int	lst_str_len(t_result *lst)
{
	int		i;
	int		res;

	res = 0;
	while (lst)
	{
		i = 0;
		while (lst->part[i])
			i++;
		res += i;
		lst = lst->next;
	}
	return (res);
}

char	*result_to_str(t_result *lst, t_buffer **buf_srt, t_buffer *buffer)
{
	char		*res;
	int			res_i;
	int			p_i;
	t_result	*start;

	if (!lst)
		return (ft_lstclr(&lst, buf_srt, buffer));
	res = malloc((lst_str_len(lst) + 1) * sizeof(char));
	start = lst;
	res_i = 0;
	while (res && lst)
	{
		p_i = 0;
		while (lst->part[p_i])
		{
			res[res_i] = lst->part[p_i];
			p_i++;
			res_i++;
		}
		lst = lst->next;
	}
	if (res)
		res[res_i] = 0;
	ft_lstclr(&start, buf_srt, buffer);
	return (res);
}
