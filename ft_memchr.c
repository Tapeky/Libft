/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:35:44 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 11:28:37 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int	i;
	unsigned char		*p;

	i = 0;
	p = (unsigned char *) s;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((char *)p + i);
		i++;
	}
	return (0);
}
