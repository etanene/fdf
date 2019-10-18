/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:15:22 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/12 17:21:41 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_itoa_base(unsigned long long num, char *str, int base, char lower)
{
	char	*digits;
	int		len;

	digits = "0123456789ABCDEF";
	len = ft_unumlen(num, base);
	str += len;
	*str-- = '\0';
	while (num)
	{
		*str-- = (digits[num % base] | lower);
		num /= base;
	}
	return (len);
}
