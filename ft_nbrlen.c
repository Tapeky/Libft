/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsadouk <tsadouk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 22:45:33 by tsadouk           #+#    #+#             */
/*   Updated: 2024/02/29 22:45:43 by tsadouk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long n, int base)
{
	int	len;

	len = 0;
	if (!base)
		base = 10;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= base;
	}
	return (len);
}