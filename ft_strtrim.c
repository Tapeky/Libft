/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:07:01 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 10:24:37 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_char_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	calc_len(char const *s1, char const *set)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (is_char_in_set(s1[i], set))
		i++;
	while (s1[i])
	{
		i++;
		len++;
	}
	i--;
	while (is_char_in_set(s1[i], set) && i)
	{
		i--;
		len--;
	}
	if (len < 0)
		len = 0;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;
	int		i;
	int		res_i;

	if (!s1 || !set)
		return (0);
	len = calc_len(s1, set);
	res = malloc((len + 1) * sizeof(char));
	i = 0;
	if (!res)
		return (res);
	while (is_char_in_set(s1[i], set))
		i++;
	res_i = 0;
	while (res_i < len)
	{
		res[res_i] = s1[i];
		res_i++;
		i++;
	}
	res[res_i] = 0;
	return (res);
}
