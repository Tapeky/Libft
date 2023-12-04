/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:38:35 by tsadouk           #+#    #+#             */
/*   Updated: 2023/11/09 16:38:35 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	reverse_str(char *str, int start, int end)
{
	char	temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

int	count_digit(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*negative(char *result, int n)
{
	int	i;

	if (n == -2147483648)
	{
		result = (char *)ft_calloc(12, sizeof(char));
		if (result == NULL)
			return (NULL);
		ft_strlcpy(result, "-2147483648", 12);
		return (result);
	}
	i = 1;
	result = (char *)malloc(sizeof(char) * (count_digit(n) + 2));
	if (!result)
		return (NULL);
	result[0] = '-';
	n = -n;
	while (n > 0)
	{
		result[i] = '0' + (n % 10);
		n /= 10;
		i++;
	}
	reverse_str(result, 1, i - 1);
	result[i] = '\0';
	return (result);
}

char	*zero(char *result)
{
	result = (char *)malloc(sizeof(char) * 2);
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		i;

	result = NULL;
	i = 0;
	if (n == 0)
		return (zero(result));
	if (n < 0)
		return (negative(result, n));
	result = (char *)ft_calloc((count_digit(n) + 1), sizeof(char));
	if (result == NULL)
		return (NULL);
	while (n > 0)
	{
		result[i++] = '0' + (n % 10);
		n /= 10;
	}
	reverse_str(result, 0, i - 1);
	return (result);
}
