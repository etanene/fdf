/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:00:30 by afalmer-          #+#    #+#             */
/*   Updated: 2019/10/19 20:43:59 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isdigit_base(char c, int base)
{
	char	*numbers;

	numbers = "ABCDEF";
	if (base >= 10 && base <= 16)
	{
		if (toupper(c) >= numbers[0] && toupper(c) <= numbers[base - 11])
			return (1);
	}
	return (0);
}

int			ft_isnumber_base(char *str, int base)
{
	if (!str)
		return (0);
	if (*str == '-' && *(str + 1))
		str++;
	while (*str)
	{
		if (ft_isdigit(*str) || ft_isdigit_base(*str, base))
			str++;
		else
			return (0);
	}
	return (1);
}
