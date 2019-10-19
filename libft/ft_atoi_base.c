/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:23:38 by afalmer-          #+#    #+#             */
/*   Updated: 2019/10/19 20:18:42 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_base(char c, int base)
{
	char	*numbers;
	int		num;

	numbers = "0123456789ABCDEF";
	num = 0;
	while (numbers[num] && num < base)
	{
		if (numbers[num] == c)
			return (num);
		num++;
	}
	return (-1);
}

long long	ft_atoi_base(char *str, int base)
{
	long long	res;
	int			sign;
	int			digit;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ((digit = ft_digit_base(*str++, base)) >= 0)
		res = res * base + digit;
	return (res * sign);
}
