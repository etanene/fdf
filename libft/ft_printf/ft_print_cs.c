/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:05:27 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/19 18:36:19 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(t_options *opt, t_buff *buffer, unsigned char c)
{
	opt->width--;
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	ft_in_buff(buffer, c);
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}

int		ft_convert_to_utf8(wchar_t c, char *lc)
{
	int		bytes;

	bytes = 0;
	if (++bytes && c <= 0x7F)
		lc[0] = c;
	else if (++bytes && c <= 0x7FF)
	{
		lc[0] = 0xC0 | (c >> 6);
		lc[1] = 0x80 | (c & 0x3F);
	}
	else if (++bytes && c <= 0xFFFF)
	{
		lc[0] = 0xE0 | (c >> 12);
		lc[1] = 0x80 | ((c >> 6) & 0x3F);
		lc[2] = 0x80 | (c & 0x3F);
	}
	else if (++bytes && c <= 0x10FFFF)
	{
		lc[0] = 0xF0 | (c >> 18);
		lc[1] = 0x80 | ((c >> 12) & 0x3F);
		lc[2] = 0x80 | ((c >> 6) & 0x3F);
		lc[3] = 0x80 | (c & 0x3F);
	}
	return (c <= 0x10FFFF ? bytes : 0);
}

void	ft_print_lc(t_options *opt, t_buff *buffer, wchar_t c)
{
	int		bytes;
	char	lc[4];
	char	*temp;

	bytes = ft_convert_to_utf8(c, lc);
	opt->width -= bytes;
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	temp = lc;
	while (bytes--)
		ft_in_buff(buffer, *temp++);
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}

void	ft_print_s(t_options *opt, t_buff *buffer, char *str)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_strnlen(str, opt->prec);
	opt->width -= len;
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	while (len--)
		ft_in_buff(buffer, *str++);
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}

void	ft_print_ls(t_options *opt, t_buff *buffer, wchar_t *str)
{
	int		len;
	int		bytes;
	char	lc[4];
	char	*temp;

	if (!str)
		str = L"(null)";
	len = ft_wstrnlen(str, opt->prec);
	opt->width -= len;
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	bytes = 0;
	while (len)
	{
		bytes = ft_convert_to_utf8(*str++, lc);
		len -= bytes;
		temp = lc;
		while (bytes--)
			ft_in_buff(buffer, *temp++);
	}
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}
