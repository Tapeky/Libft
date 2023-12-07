/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomoron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:41:15 by tomoron           #+#    #+#             */
/*   Updated: 2023/11/15 14:31:19 by tomoron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_protected_atoi(const char *str)
{
	long long	res;
	int			inv;

	res = 0;
	inv = 1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			inv *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	if (res > 2147483647)
		return (-2);
	return ((int)res * inv);
}
