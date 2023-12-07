/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:03:11 by tomoron           #+#    #+#             */
/*   Updated: 2023/12/04 09:56:26 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_buffer	*buffer_start;
	t_buffer		*buffer;
	int				nl_found;
	int				start;
	t_result		*result;

	nl_found = 0;
	result = 0;
	start = 0;
	buffer = create_find_buffer(&buffer_start, fd);
	if (BUFFER_SIZE < 0 || !buffer)
		return (0);
	if (fd >= 0 && (buffer->i == 0 || buffer->i == buffer->rd_l))
		buffer->rd_l = read(fd, buffer->str, BUFFER_SIZE);
	else
		start = buffer->i;
	while (fd >= 0 && !nl_found && buffer->rd_l > 0)
	{
		nl_found = find_nl(buffer, &start);
		if (!ft_lstadd_bak(&result, buffer->str, buffer->i, start))
			return (ft_lstclr(&result, NULL, NULL));
		if (!nl_found)
			buffer->rd_l = read(fd, buffer->str, BUFFER_SIZE);
	}
	return (result_to_str(result, &buffer_start, buffer));
}

int	find_nl(t_buffer *buffer, int *start)
{
	int	nl_found;

	nl_found = 0;
	if (buffer->i == BUFFER_SIZE)
		*start = 0;
	buffer->i = *start;
	while (buffer->i < buffer->rd_l && !nl_found)
	{
		if (buffer->str[buffer->i] == '\n')
			nl_found = 1;
		(buffer->i)++;
	}
	return (nl_found);
}

t_buffer	*create_find_buffer(t_buffer **buffer_start, int fd)
{
	t_buffer	*current;
	t_buffer	*last;

	current = *buffer_start;
	last = 0;
	while (current)
	{
		if (current->fd == fd)
			return (current);
		last = current;
		current = current->next;
	}
	if (last)
	{
		last->next = malloc(sizeof(t_buffer));
		last = last->next;
	}
	else
	{
		last = malloc(sizeof(t_buffer));
		*buffer_start = last;
	}
	if (last)
		init_buffer(last, fd);
	return (last);
}

void	init_buffer(t_buffer *last, int fd)
{
	last->fd = fd;
	last->i = 0;
	last->rd_l = 0;
	last->next = 0;
}

void	ft_lstdelon(t_buffer *node, t_buffer **start)
{
	t_buffer	*current;
	t_buffer	*next;

	if (!start || !node || !*start)
		return ;
	current = *start;
	while (current->next && current->next != node)
		current = current->next;
	next = node->next;
	free(node);
	if (node == *start)
		*start = next;
	else
		current->next = next;
}
