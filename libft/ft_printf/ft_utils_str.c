/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:13:29 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/11 19:49:38 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strnlen(char *str, int n)
{
	int		len;

	len = 0;
	while (n--)
	{
		if (!*str)
			break ;
		len++;
		str++;
	}
	return (len);
}

int		ft_wstrnlen(wchar_t *str, int n)
{
	int		len;
	int		bytes;

	len = 0;
	while (*str && n)
	{
		bytes = 0;
		if (*str <= 0x7F)
			bytes = 1;
		else if (*str <= 0x7FF)
			bytes = 2;
		else if (*str <= 0xFFFF)
			bytes = 3;
		else if (*str <= 0x10FFFF)
			bytes = 4;
		if (n >= bytes || n < 0)
		{
			len += bytes;
			n -= bytes;
			str++;
		}
		else
			break ;
	}
	return (len);
}

int		ft_rstrnlen(char *str, int n)
{
	int		len;

	len = 0;
	while (n--)
	{
		if (!*str)
			break ;
		if ((*str >= 7 && *str <= 13) || *str == '\e')
			len++;
		len++;
		str++;
	}
	return (len);
}
