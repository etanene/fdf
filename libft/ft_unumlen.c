/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 19:38:43 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/13 19:39:01 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_unumlen(unsigned long long num, int base)
{
	int		len;

	len = 0;
	while (num /= base)
		len++;
	return (len + 1);
}
