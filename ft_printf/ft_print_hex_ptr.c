/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 15:58:57 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/05 15:58:58 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_calc_hex_len(long unsigned int n, t_flags flags)
{
	int					res;

	res = 1;
	if (n == 0 && flags.precision == 0)
		return (0);
	while (n > 15)
	{
		res++;
		n /= 16;
	}
	return (res);
}

void	ft_put_hex(unsigned long int n, char mode)
{
	if (n > 15)
		ft_put_hex(n / 16, mode);
	if (mode == 'L')
		write(1, &"0123456789abcdef"[n % 16], 1);
	if (mode == 'U')
		write(1, &"0123456789ABCDEF"[n % 16], 1);
}

size_t	ft_print_ptr(void *ptr, t_flags flags)
{
	int	len;
	int	res;

	res = 0;
	if (!ptr)
		return (ft_print_str("(nil)", flags));
	len = ft_calc_hex_len((long unsigned int)ptr, flags) + 2;
	if (flags.min_width && !flags.left_justify)
		res += ft_fill_width(' ', flags.min_width - len);
	ft_putstr("0x");
	ft_put_hex((unsigned long int)ptr, 'L');
	if (flags.min_width && flags.left_justify)
		res += ft_fill_width(' ', flags.min_width - len);
	return (res + len);
}

size_t	ft_write_blank(int blank_len, t_flags flags, char mode)
{
	size_t	res;

	res = 0;
	if (blank_len > 0 && ((flags.left_justify && mode == 'A')
			|| (!flags.left_justify && mode == 'B')))
	{
		if (flags.zero_padding && flags.precision == -1)
			res += ft_fill_width('0', blank_len);
		else
			res += ft_fill_width(' ', blank_len);
	}
	return (res);
}

size_t	ft_print_hex(unsigned int nb, t_flags flags, char mode)
{
	int		blank_len;
	int		zero_len;
	int		number_len;
	size_t	res;

	number_len = ft_calc_hex_len(nb, flags);
	res = number_len;
	zero_len = 0;
	if (flags.precision > number_len)
		zero_len = flags.precision - number_len;
	blank_len = flags.min_width - zero_len - number_len;
	blank_len -= flags.zero_x_prefix * 2;
	res += ft_write_blank(blank_len, flags, 'B');
	if (flags.zero_x_prefix && nb && mode == 'L')
		res += ft_putstr("0x");
	if (flags.zero_x_prefix && nb && mode == 'U')
		res += ft_putstr("0X");
	res += ft_fill_width('0', zero_len);
	if (flags.precision != 0 || nb != 0)
		ft_put_hex(nb, mode);
	res += ft_write_blank(blank_len, flags, 'A');
	return (res);
}
