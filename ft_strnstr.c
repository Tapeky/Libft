/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 02:50:08 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/01 13:21:17 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	s_i;
	unsigned int	tf_i;
	unsigned int	tf_l;
	char			*res;

	s_i = 0;
	tf_l = 0;
	res = (char *)str;
	while (to_find && to_find[tf_l])
		tf_l++;
	if (tf_l == 0)
		return (res);
	while (str && str[s_i] && s_i <= len)
	{
		tf_i = 0;
		while (str[s_i + tf_i] == to_find[tf_i]
			&& to_find[tf_i] && s_i + tf_i <= len)
			tf_i++;
		if (tf_i == tf_l && s_i + tf_i <= len)
			return (res + s_i);
		s_i++;
	}
	return (0);
}
