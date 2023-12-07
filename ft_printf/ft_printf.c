/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:41:38 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/08 14:51:19 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_check_placeholders(const char *str)
{
	int	err;

	err = 0;
	while (*str)
	{
		while (*str && *str != '%')
			str++;
		if (*str == '%')
		{
			str++;
			while (*str == '-' || *str == '0' || *str == '#'
				|| *str == ' ' || *str == '+' || ft_isdigit(*str))
				str++;
			if (*str != 'c' && *str != 's' && *str != 'p' && *str != 'd'
				&& *str && *str != 'i' && *str != 'u' && *str != 'x'
				&& *str != 'X' && *str != '%')
				err = 1;
			if (!*str && err == 0)
				err = 2;
			if (*str == '%')
				str++;
		}
	}
	return (err);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	res;
	char	*s;
	int		err;

	if (!str)
		return (-1);
	va_start(args, str);
	res = 0;
	s = (char *)str;
	err = ft_check_placeholders(s);
	res += ft_write_str_part(&s);
	while (*s)
	{
		res += ft_parse_arg(&s, args, &err);
		if (err == 3)
			break ;
		res += ft_write_str_part(&s);
	}
	va_end(args);
	if (err >= 2)
		return (-1);
	return (res);
}
