/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 01:08:34 by tomoron           #+#    #+#             */
/*   Updated: 2023/10/31 18:26:25 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (i == size)
		dest[i - 1] = 0;
	else
		dest[i] = 0;
	return (ft_strlen(src));
}
