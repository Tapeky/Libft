/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 02:38:46 by tomoron           #+#    #+#             */
/*   Updated: 2023/10/31 18:15:42 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	char				*res;
	unsigned long int	i;

	if (nb == 0 || size == 0)
		return (malloc(1));
	if ((long long)nb < 0 || (long long) size < 0)
		return (0);
	res = malloc(nb * size);
	i = 0;
	while (i < (nb * size) && res)
	{
		res[i] = 0;
		i++;
	}
	return ((void *)res);
}
