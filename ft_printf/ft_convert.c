/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 23:24:31 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/07 23:55:33 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_fill_width(char c, int n)
{
	int	res;

	res = n;
	if (res < 0)
		res = 0;
	while (n > 0)
	{
		ft_putchar(c);
		n--;
	}
	return (res);
}

size_t	ft_print_char(int c, t_flags flags)
{
	int	res;

	res = 0;
	if (flags.min_width && !flags.left_justify)
		res += ft_fill_width(' ', flags.min_width - 1);
	res += ft_putchar((char)c);
	if (flags.min_width && flags.left_justify)
		res += ft_fill_width(' ', flags.min_width - 1);
	return (res);
}

size_t	ft_print_str(char *s, t_flags flags)
{
	int	nb_to_print;
	int	res;

	res = 0;
	if (!s && (flags.precision >= 6 || flags.precision == -1))
		s = "(null)";
	else if (!s)
		s = "";
	nb_to_print = ft_strlen(s);
	if (flags.precision != -1 && nb_to_print > flags.precision)
		nb_to_print = flags.precision;
	if (flags.min_width && !flags.left_justify)
		res += ft_fill_width(' ', flags.min_width - nb_to_print);
	write(1, s, nb_to_print);
	if (flags.min_width && flags.left_justify)
		res += ft_fill_width(' ', flags.min_width - nb_to_print);
	return (res + nb_to_print);
}

size_t	ft_convert(char *s, t_flags flags, va_list args, int err)
{
	if (*s == 'c')
		return (ft_print_char(va_arg(args, int), flags));
	else if (*s == 's')
		return (ft_print_str(va_arg(args, char *), flags));
	else if (*s == 'p')
		return (ft_print_ptr(va_arg(args, void *), flags));
	else if (*s == 'd' || *s == 'i')
		return (ft_print_signed_int(va_arg(args, int), flags));
	else if (*s == 'u')
		return (ft_print_unsigned_int(va_arg(args, unsigned int), flags));
	else if (*s == 'x')
		return (ft_print_hex(va_arg(args, unsigned int), flags, 'L'));
	else if (*s == 'X')
		return (ft_print_hex(va_arg(args, unsigned int), flags, 'U'));
	else if (*s == '%')
		return (ft_putstr("%"));
	else if (err != 2)
		return (ft_putstr("%"));
	else
		return (0);
}
