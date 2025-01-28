/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:18:26 by tsadouk           #+#    #+#             */
/*   Updated: 2023/11/09 14:18:26 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	precheck(const char *s1, const char *s2)
{
	return (s1 == NULL || s2 == NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_len;
	int		i;
	int		index;
	char	*result;

	if (precheck(s1, s2))
		return (NULL);
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	index = i;
	i = -1;
	while (s2[++i])
	{
		result[index] = s2[i];
		index++;
	}
	result[index] = '\0';
	return (result);
}
