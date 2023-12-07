/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:35:44 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 10:25:44 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (p[i] == (unsigned char)c)
			return (p + i);
		i--;
	}
	return (NULL);
}
