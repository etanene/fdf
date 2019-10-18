/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_f.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:54:27 by afalmer-          #+#    #+#             */
/*   Updated: 2019/02/19 18:35:46 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rounding(char *number, int len)
{
	int		count;

	count = len;
	if (number[len] >= '5')
	{
		number[len--] = '\0';
		while (len >= 0)
		{
			if (number[len] == '9')
				number[len] = '0';
			else if (number[len] != '.')
				break ;
			len--;
		}
		if (len >= 0)
			number[len] += 1;
		else
		{
			ft_memmove(number + 1, number, count);
			number[0] = '1';
		}
	}
	else
		number[len] = '\0';
}

char	*ft_get_fnum(t_fnum *fnum, int prec, int ilen)
{
	char	*number;
	int		i;
	char	*ipart;
	char	*fpart;

	prec += 2;
	number = (char*)malloc(ilen + prec + 1);
	ipart = fnum->ipart ? fnum->ipart : "0";
	fpart = fnum->fpart ? fnum->fpart : "0";
	i = 0;
	while (i < ilen)
		number[i++] = *ipart++;
	number[i++] = '.';
	while (fnum->zero-- && (i < ilen + prec))
		number[i++] = '0';
	while (*fpart && (i < ilen + prec))
		number[i++] = *fpart++;
	while (i < ilen + prec)
		number[i++] = '0';
	ft_rounding(number, i - 1);
	number[i - 2] = (prec == 2) ? '\0' : number[i - 2];
	return (number);
}

char	ft_get_sign_f(t_options *opt, char sign)
{
	char	res;

	res = 0;
	if (sign)
	{
		res = '-';
		opt->width--;
	}
	else if (opt->flags & F_PLUS)
	{
		res = '+';
		opt->width--;
	}
	else if (opt->flags & F_SP)
	{
		sign = ' ';
		opt->width--;
	}
	if (opt->flags & F_MINUS)
		opt->flags &= ~F_NULL;
	if (opt->prec == -1)
		opt->prec = 6;
	return (res);
}

void	ft_print_f(t_options *opt, t_buff *buffer, t_fnum *fnum)
{
	int		len;
	char	sign;
	char	*number;
	char	*temp;

	sign = ft_get_sign_f(opt, fnum->sign);
	len = 0;
	if (!fnum->ipart)
		len++;
	else
		len = ft_strnlen(fnum->ipart, -1);
	opt->width -= opt->prec ? opt->prec + len + 1 : len;
	if (!(opt->flags & (F_NULL + F_MINUS)))
		ft_print_width(buffer, &opt->width, ' ');
	if (sign)
		ft_in_buff(buffer, sign);
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	number = ft_get_fnum(fnum, opt->prec, len);
	temp = number;
	while (*temp)
		ft_in_buff(buffer, *temp++);
	ft_strdel(&number);
	ft_print_width(buffer, &opt->width, ' ');
}
