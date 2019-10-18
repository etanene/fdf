/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diuoxb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 00:55:24 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/19 18:38:23 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_get_sign(t_options *opt, unsigned long long *unum, long long num)
{
	char	sign;

	*unum = num;
	sign = 0;
	if (num < 0)
	{
		sign = '-';
		*unum = -num;
		opt->width--;
	}
	else if (opt->flags & F_PLUS)
	{
		sign = '+';
		opt->width--;
	}
	else if (opt->flags & F_SP)
	{
		sign = ' ';
		opt->width--;
	}
	if (opt->flags & F_MINUS || opt->prec >= 0)
		opt->flags &= ~F_NULL;
	return (sign);
}

void	ft_print_di(t_options *opt, t_buff *buffer, long long num)
{
	unsigned long long	unum;
	char				sign;
	char				number[MAX_DEC];
	char				*temp;
	int					len;

	sign = ft_get_sign(opt, &unum, num);
	len = 0;
	if (!unum)
		number[len++] = '0';
	else
		len = ft_itoa_base(unum, number, 10, opt->flags & F_LOWER);
	opt->prec = (len > opt->prec && (opt->prec || num)) ? len : opt->prec;
	opt->width -= opt->prec;
	if (!(opt->flags & (F_NULL + F_MINUS)))
		ft_print_width(buffer, &opt->width, ' ');
	if (sign)
		ft_in_buff(buffer, sign);
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	ft_print_prec(buffer, opt->prec, len);
	temp = number;
	while (len-- && (opt->prec || num))
		ft_in_buff(buffer, *temp++);
	ft_print_width(buffer, &opt->width, ' ');
}

void	ft_reset_options(t_options *opt)
{
	if (opt->flags & F_MINUS)
		opt->flags &= ~F_NULL;
	if (opt->flags & F_SHARP)
	{
		if (opt->base == 16)
			opt->width -= 2;
		else if (opt->base == 8)
		{
			opt->width -= 1;
			opt->prec -= 1;
		}
		else if (opt->base == 2)
			opt->width -= 2;
	}
}

void	ft_print_uoxb(t_options *opt, t_buff *buffer, unsigned long long num)
{
	char	number[MAX_BIN];
	char	*temp;
	int		len;

	ft_reset_options(opt);
	len = 0;
	if (!num)
		number[len++] = '0';
	else
		len = ft_itoa_base(num, number, opt->base, opt->flags & F_LOWER);
	if (len > opt->prec && opt->prec)
		opt->prec = len;
	opt->width -= opt->prec;
	if (!(opt->flags & (F_NULL + F_MINUS)))
		ft_print_width(buffer, &opt->width, ' ');
	if ((opt->flags & F_SHARP) && (num || opt->spec == 'p'))
		ft_print_sharp(buffer, opt);
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	ft_print_prec(buffer, opt->prec, len);
	temp = number;
	while (len-- && opt->prec)
		ft_in_buff(buffer, *temp++);
	ft_print_width(buffer, &opt->width, ' ');
}
