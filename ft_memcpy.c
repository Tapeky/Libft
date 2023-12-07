/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:42:28 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 11:05:58 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*d;
	char			*s;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	while (i < n && d && s)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}
