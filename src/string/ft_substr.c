/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:22:18 by tsadouk           #+#    #+#             */
/*   Updated: 2023/11/09 14:22:18 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;

	result = NULL;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len + start)
		len = ft_strlen(s) - start;
	if ((size_t)start >= ft_strlen(s))
	{
		result = ft_calloc(1, sizeof(char));
		return (result);
	}
	result = (char *)malloc(sizeof(char) * len + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, (unsigned char *) s + start, len);
	result[len] = '\0';
	return (result);
}
