/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:21:52 by tsadouk           #+#    #+#             */
/*   Updated: 2023/11/09 14:21:52 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *set)
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

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*result;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	if (start > end)
		return (ft_strdup(""));
	while (is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end], set))
		end--;
	result = malloc(sizeof(char) * (end - start + 2));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		result[i++] = s1[start++];
	result[i] = '\0';
	return (result);
}
