/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 16:06:48 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/05 16:06:49 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_calc_unsigned_int_len(unsigned int nb, t_flags flags)
{
	int	res;

	res = 1;
	if (nb == 0 && flags.precision == 0)
		return (0);
	while (nb > 9)
	{
		res++;
		nb /= 10;
	}
	return (res);
}

size_t	ft_print_unsigned_int(unsigned int nb, t_flags flags)
{
	int		blank_len;
	int		zero_len;
	int		number_len;
	size_t	res;

	number_len = ft_calc_unsigned_int_len(nb, flags);
	res = number_len;
	zero_len = 0;
	if (flags.precision > number_len)
		zero_len = flags.precision - number_len;
	blank_len = flags.min_width - zero_len - number_len;
	if (blank_len > 0 && !flags.left_justify && flags.zero_padding
		&& flags.precision == -1)
		res += ft_fill_width('0', blank_len);
	else if (blank_len > 0 && !flags.left_justify)
		res += ft_fill_width(' ', blank_len);
	res += ft_fill_width('0', zero_len);
	if (flags.precision != 0 || nb != 0)
		ft_put_lu_nbr(nb);
	if (blank_len > 0 && flags.left_justify && flags.zero_padding)
		res += ft_fill_width('0', blank_len);
	else if (blank_len > 0 && flags.left_justify)
		res += ft_fill_width(' ', blank_len);
	return (res);
}
