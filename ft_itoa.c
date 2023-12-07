/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 02:36:12 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/02 10:16:45 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_len(long int n)
{
	int			res;

	res = 1;
	if (n < 0)
	{
		res++;
		n *= -1;
	}
	while (n > 9)
	{
		res++;
		n /= 10;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			nb_len;
	int			i;
	long int	temp_nb;

	temp_nb = (long int)n;
	nb_len = get_number_len(n);
	res = malloc((nb_len + 1) * sizeof(char));
	if (!res)
		return (res);
	i = 0;
	if (temp_nb < 0)
	{
		res[0] = '-';
		temp_nb *= -1;
	}
	while (temp_nb > 9)
	{
		res[nb_len - i - 1] = (temp_nb % 10) + '0';
		temp_nb /= 10;
		i++;
	}
	res[nb_len - i - 1] = temp_nb + '0';
	res[nb_len] = 0;
	return (res);
}
