/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 03:16:22 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 10:47:42 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	dst_len;
	unsigned int	i;
	unsigned int	ret_val;

	if (!dst || !src)
		return (0);
	dst_len = ft_strlen(dst);
	if (!size)
		return (ft_strlen(src));
	if (size < dst_len)
		return (ft_strlen(src) + size);
	i = 0;
	ret_val = dst_len + ft_strlen(src);
	while (src[i] && size > dst_len + 1)
	{
		dst[dst_len] = src[i];
		i++;
		dst_len++;
	}
	dst[dst_len] = 0;
	return (ret_val);
}
