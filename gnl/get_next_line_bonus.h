/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:24:39 by tomoron           #+#    #+#             */
/*   Updated: 2023/12/04 09:57:06 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_result
{
	char			part[BUFFER_SIZE + 1];
	struct s_result	*next;

}	t_result;

typedef struct s_buffer
{
	char			str[BUFFER_SIZE];
	int				i;
	int				rd_l;
	int				fd;
	struct s_buffer	*next;
}	t_buffer;

char		*get_next_line(int fd);
char		*result_to_str(t_result *lst, t_buffer **buf_st, t_buffer *buffer);
t_result	*ft_lstadd_bak(t_result **lst, char *buffer, int n, int start);
char		*ft_lstclr(t_result **lst, t_buffer **buf_str, t_buffer *buffer);
int			find_nl(t_buffer *buffer, int *start);
t_buffer	*create_find_buffer(t_buffer **buffer_start, int fd);
void		init_buffer(t_buffer *last, int fd);
void		ft_lstdelon(t_buffer *node, t_buffer **start);
#endif
