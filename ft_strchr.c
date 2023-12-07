/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:35:44 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 11:08:17 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (res[i])
	{
		if (res[i] == (unsigned char)c)
			return (res + i);
		i++;
	}
	if (res[i] == (unsigned char)c)
		return (res + i);
	return (NULL);
}
