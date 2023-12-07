/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 10:30:03 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/21 15:37:48 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (*sep == c)
			return (1);
		sep++;
	}
	return (0);
}

int	ft_count_parts(char *str, char *charset)
{
	int	res;

	res = 0;
	while (ft_is_sep(*str, charset) && *str)
		str++;
	while (*str)
	{
		while (!ft_is_sep(*str, charset) && *str)
			str++;
		while (ft_is_sep(*str, charset) && *str)
			str++;
		res++;
	}
	return (res + 1);
}

int	ft_strlen_sep(char *str, char *charset)
{
	int	res;

	res = 0;
	while (*str && !ft_is_sep(*str, charset))
	{
		res++;
		str++;
	}
	return (res + 1);
}

char	**ft_split_set(char *str, char *charset)
{
	int		str_len;
	int		nb_str;
	char	**res;
	int		i;
	int		j;

	nb_str = ft_count_parts(str, charset);
	res = (char **)malloc(nb_str * sizeof(char *));
	i = -1;
	while (ft_is_sep(*str, charset))
		str++;
	while (++i < nb_str - 1 && *str && res)
	{
		str_len = ft_strlen_sep(str, charset);
		res[i] = malloc(str_len * sizeof(char));
		j = 0;
		while (res[i] && *str && !ft_is_sep(*str, charset))
			res[i][j++] = *(str++);
		res[i][j] = 0;
		while (ft_is_sep(*str, charset))
			str++;
	}
	if (res)
		res[i] = 0;
	return (res);
}
