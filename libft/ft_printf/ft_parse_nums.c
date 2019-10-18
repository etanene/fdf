/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 23:30:07 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/19 18:35:28 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_num(t_options *opt, t_buff *buffer, long long num)
{
	if (opt->spec == 'D')
		ft_print_di(opt, buffer, (long)num);
	else if (opt->length == 0)
		ft_print_di(opt, buffer, (int)num);
	else if (opt->length == LEN_HH)
		ft_print_di(opt, buffer, (char)num);
	else if (opt->length == LEN_H)
		ft_print_di(opt, buffer, (short)num);
	else if (opt->length == LEN_L)
		ft_print_di(opt, buffer, (long)num);
	else if (opt->length == LEN_LL)
		ft_print_di(opt, buffer, (long long)num);
	else if (opt->length == LEN_J)
		ft_print_di(opt, buffer, (intmax_t)num);
	else if (opt->length == LEN_Z)
		ft_print_di(opt, buffer, (ssize_t)num);
}

void	ft_parse_unum(t_options *opt, t_buff *buffer, unsigned long long unum)
{
	if (opt->spec == 'U' || opt->spec == 'O')
		ft_print_uoxb(opt, buffer, (unsigned long)unum);
	else if (opt->length == 0)
		ft_print_uoxb(opt, buffer, (unsigned int)unum);
	else if (opt->length == LEN_HH)
		ft_print_uoxb(opt, buffer, (unsigned char)unum);
	else if (opt->length == LEN_H)
		ft_print_uoxb(opt, buffer, (unsigned short)unum);
	else if (opt->length == LEN_L)
		ft_print_uoxb(opt, buffer, (unsigned long)unum);
	else if (opt->length == LEN_LL)
		ft_print_uoxb(opt, buffer, (unsigned long long)unum);
	else if (opt->length == LEN_J)
		ft_print_uoxb(opt, buffer, (uintmax_t)unum);
	else if (opt->length == LEN_Z)
		ft_print_uoxb(opt, buffer, (size_t)unum);
}

int		ft_get_zero(unsigned long long num, int shift, char *fpart)
{
	int		len;
	int		zero;
	int		power;

	len = ft_strnlen(fpart, -1);
	zero = 0;
	power = 0;
	while (power < 64)
	{
		if (num & (1ULL << power))
		{
			zero = 64 - power + shift - len;
			break ;
		}
		power++;
	}
	return (zero);
}

void	ft_parse_fnum(t_options *opt, t_buff *buffer, double num, \
				void (*ft_print)(t_options*, t_buff*, t_fnum*))
{
	t_fnum	fnum;

	fnum.num.f = num;
	fnum.sign = (fnum.num.ll & (1ULL << 63)) ? 1 : 0;
	fnum.exp = ((fnum.num.ll >> 52) & 0x7FF) - 1023;
	fnum.man = (fnum.num.ll & 0x1FFFFFFFFFFFFF) | 0x10000000000000;
	fnum.ipart = NULL;
	fnum.fpart = NULL;
	fnum.zero = 0;
	if (fnum.exp >= 52)
		fnum.ipart = ft_get_part(fnum.man, fnum.exp - 52, ft_get_ipart);
	else if (fnum.exp >= 0)
	{
		fnum.ipart = ft_get_part(fnum.man >> (52 - fnum.exp), 0, ft_get_ipart);
		fnum.fpart = ft_get_part(fnum.man << (fnum.exp + 12), 0, ft_get_fpart);
		fnum.zero = ft_get_zero(fnum.man << (fnum.exp + 12), 0, fnum.fpart);
	}
	else if (fnum.exp >= -1022)
	{
		fnum.fpart = ft_get_part(fnum.man << 11, -(fnum.exp + 1), ft_get_fpart);
		fnum.zero = ft_get_zero(fnum.man << 11, -(fnum.exp + 1), fnum.fpart);
	}
	ft_print(opt, buffer, &fnum);
	ft_strdel(&fnum.ipart);
	ft_strdel(&fnum.fpart);
}

void	ft_parse_lfnum(t_options *opt, t_buff *buffer, long double num, \
				void (*ft_print)(t_options*, t_buff*, t_fnum*))
{
	t_fnum	fnum;

	fnum.num.lf = num;
	fnum.sign = (*(&fnum.num.ll + 1) & (1ULL << 15)) ? 1 : 0;
	fnum.exp = (*(&fnum.num.ll + 1) & 0x7FFF) - 16383;
	fnum.man = fnum.num.ll;
	fnum.ipart = NULL;
	fnum.fpart = NULL;
	fnum.zero = 0;
	if (fnum.exp >= 64)
		fnum.ipart = ft_get_part(fnum.man, fnum.exp - 63, ft_get_ipart);
	else if (fnum.exp >= 0)
	{
		fnum.ipart = ft_get_part(fnum.man >> (63 - fnum.exp), 0, ft_get_ipart);
		fnum.fpart = ft_get_part(fnum.man << (fnum.exp + 1), 0, ft_get_fpart);
		fnum.zero = ft_get_zero(fnum.man << (fnum.exp + 1), 0, fnum.fpart);
	}
	else if (fnum.exp >= -16382)
	{
		fnum.fpart = ft_get_part(fnum.man, -(fnum.exp + 1), ft_get_fpart);
		fnum.zero = ft_get_zero(fnum.man, -(fnum.exp + 1), fnum.fpart);
	}
	ft_print(opt, buffer, &fnum);
	ft_strdel(&fnum.ipart);
	ft_strdel(&fnum.fpart);
}
