/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:59:20 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 11:00:04 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h" 

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;
	unsigned int	res_len;

	res_len = 0;
	if (!s)
		return (0);
	if (ft_strlen(s) > start)
		while (res_len < len && s[start + res_len])
			res_len++;
	res = malloc((res_len + 1) * sizeof(char));
	if (!res)
		return (res);
	i = 0;
	while (i < res_len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = 0;
	return (res);
}
