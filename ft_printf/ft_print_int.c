/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:52:46 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/05 15:53:56 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calc_signed_int_len(int nb, t_flags flags)
{
	int			res;
	long int	n;

	res = 1;
	n = (long int) nb;
	if (flags.precision == 0 && nb == 0)
		return (0);
	if (n < 0)
	{
		n = n * -1;
	}
	while (n > 9)
	{
		res++;
		n /= 10;
	}
	return (res);
}

size_t	ft_putsign(int nb, t_flags flags, int sign)
{
	if (nb < 0)
		return (ft_putchar('-'));
	if (sign && flags.blank_positive)
		return (ft_putchar(' '));
	if (sign)
		return (ft_putchar('+'));
	return (0);
}

int	ft_print_signed_int_blank_sign(int nb, t_flags flags, size_t *res)
{
	int	blank_len;
	int	zero_len;
	int	number_len;
	int	sign;

	number_len = ft_calc_signed_int_len(nb, flags);
	sign = (nb < 0) || flags.always_sign_number || flags.blank_positive;
	zero_len = 0;
	if (flags.precision > number_len)
		zero_len = flags.precision - number_len;
	blank_len = flags.min_width - zero_len - number_len - sign;
	if (blank_len > 0 && !flags.left_justify && ((!flags.zero_padding
				&& nb != 0) || (flags.zero_padding && flags.precision != -1)))
		*res += ft_fill_width(' ', blank_len);
	*res += ft_putsign(nb, flags, sign);
	if (blank_len > 0 && !flags.left_justify && flags.zero_padding
		&& flags.precision == -1)
		*res += ft_fill_width('0', blank_len);
	*res += ft_fill_width('0', zero_len);
	return (blank_len);
}

void	ft_put_lu_nbr(long unsigned int nb)
{
	if (nb > 9)
		ft_put_lu_nbr(nb / 10);
	ft_putchar("0123456789"[nb % 10]);
}

size_t	ft_print_signed_int(int nb, t_flags flags)
{
	int			blank_len;
	long int	n;
	size_t		res;

	res = ft_calc_signed_int_len(nb, flags);
	n = (long int)nb;
	if (n < 0)
		n *= -1;
	blank_len = ft_print_signed_int_blank_sign(nb, flags, &res);
	if (flags.precision != 0 || nb != 0)
		ft_put_lu_nbr((long unsigned int)n);
	if (blank_len > 0 && flags.left_justify)
	{
		if (flags.zero_padding)
			res += ft_fill_width('0', blank_len);
		else
			res += ft_fill_width(' ', blank_len);
	}
	return (res);
}
