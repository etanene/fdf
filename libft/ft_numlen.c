/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 17:21:25 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/13 19:38:39 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(long long num)
{
	int					len;
	unsigned long long	unum;

	len = 0;
	unum = num;
	if (num < 0)
	{
		unum = -num;
		len++;
	}
	while (unum /= 10)
		len++;
	return (len + 1);
}
