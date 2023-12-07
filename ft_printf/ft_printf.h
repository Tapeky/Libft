/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 23:42:00 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/15 14:31:34 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	left_justify;
	int	zero_padding;
	int	always_sign_number;
	int	blank_positive;
	int	zero_x_prefix;
	int	min_width;
	int	precision;
}	t_flags;

int		ft_printf(const char *str, ...);
size_t	ft_write_str_part(char **s);
size_t	ft_parse_arg(char **s, va_list args, int *err);
size_t	ft_convert(char *s, t_flags flags, va_list args, int err);
size_t	ft_putchar(char c);
size_t	ft_putstr(char *s);
size_t	ft_strlen(char const *s);
int		ft_protected_atoi(const char *s);
int		ft_isdigit(int c);
size_t	ft_print_unsigned_int(unsigned int nb, t_flags flags);
size_t	ft_print_signed_int(int nb, t_flags flags);
size_t	ft_fill_width(char c, int n);
size_t	ft_print_hex(unsigned int nb, t_flags flags, char mode);
size_t	ft_print_ptr(void *ptr, t_flags flags);
size_t	ft_print_str(char *s, t_flags flags);
void	ft_put_lu_nbr(long unsigned int nb);

#endif
