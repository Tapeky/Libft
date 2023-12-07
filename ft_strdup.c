/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 14:55:26 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 11:13:46 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*res;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!src)
		return (0);
	while (src[len])
		len++;
	res = (char *)malloc((len + 1) * sizeof(char));
	if (!res)
		return (0);
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
