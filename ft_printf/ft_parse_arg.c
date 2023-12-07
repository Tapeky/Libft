/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:43:10 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/15 14:32:59 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_char_in_flags(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] == '-' || s[i] == '0' || s[i] == '#'
		|| s[i] == ' ' || s[i] == '+')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_get_width_precision(char **s, va_list args, t_flags *flags, int *err)
{
	if (**s == '*')
		flags->min_width = va_arg(args, int);
	else
		flags->min_width = ft_protected_atoi(*s);
	while (ft_isdigit(**s) || **s == '*')
		(*s)++;
	flags->precision = -1;
	if (**s == '.' && *(*s + 1) == '*')
		flags->precision = va_arg(args, int);
	else if (**s == '.')
	{
		if (ft_isdigit(*(*s + 1)))
			flags->precision = ft_protected_atoi(*s + 1);
		else
			flags->precision = 0;
		(*s)++;
	}
	while (ft_isdigit(**s) || **s == '.' || **s == '*')
		(*s)++;
	if (flags->min_width == -2 || flags->precision == -2)
		*err = 3;
}

void	ft_get_flags(char **s, va_list args, t_flags *flags, int *err)
{
	flags->left_justify = ft_is_char_in_flags(*s, '-');
	flags->zero_padding = ft_is_char_in_flags(*s, '0');
	flags->always_sign_number = ft_is_char_in_flags(*s, '+');
	flags->blank_positive = ft_is_char_in_flags(*s, ' ');
	flags->zero_x_prefix = ft_is_char_in_flags(*s, '#');
	while (**s == '-' || **s == '0' || **s == '#'
		|| **s == ' ' || **s == '+')
	{
		(*s)++;
	}
	return (ft_get_width_precision(s, args, flags, err));
}

size_t	ft_parse_arg(char **s, va_list args, int *err)
{
	t_flags	flags;
	size_t	res;

	res = 0;
	if (**s == '%')
	{
		(*s)++;
		ft_get_flags(s, args, &flags, err);
		if (*err == 3)
			return (0);
		res += ft_convert(*s, flags, args, *err);
		if (**s == 'c' || **s == 's' || **s == 'p' || **s == 'd'
			|| **s == 'i' || **s == 'u' || **s == 'x'
			|| **s == 'X' || **s == '%')
			(*s)++;
	}
	return (res);
}
