/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_prk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 20:00:27 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/19 17:05:47 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p(t_options *opt, t_buff *buffer, void *pointer)
{
	unsigned long long	addr;

	addr = (unsigned long long)pointer;
	opt->base = 16;
	opt->flags |= F_LOWER;
	opt->flags |= F_SHARP;
	ft_print_uoxb(opt, buffer, addr);
}

void	ft_print_rand(t_options *opt, t_buff *buffer)
{
	opt->width--;
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	ft_in_buff(buffer, opt->spec);
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}

void	ft_print_r(t_options *opt, t_buff *buffer, char *str)
{
	int		len;

	if (!str)
		str = "(null)";
	len = ft_rstrnlen(str, opt->prec);
	opt->width -= len;
	if (!(opt->flags & F_MINUS))
		ft_print_width(buffer, &opt->width, (opt->flags & F_NULL) ? '0' : ' ');
	while (len--)
	{
		if ((*str >= 7 && *str <= 13) || *str == '\e')
			ft_in_buff(buffer, '\\');
		ft_in_buff(buffer, *str++);
	}
	if (opt->flags & F_MINUS)
		ft_print_width(buffer, &opt->width, ' ');
}

void	ft_reset_opt_k(t_options *opt)
{
	opt->flags = 0;
	opt->width = -1;
	opt->prec = 2;
	opt->base = 10;
}

void	ft_print_k(t_options *opt, t_buff *buffer, unsigned long long unum)
{
	int		sec;
	int		minutes;
	int		hours;

	sec = unum % 60;
	unum /= 60;
	minutes = unum % 60;
	unum /= 60;
	hours = unum;
	ft_reset_opt_k(opt);
	if (hours)
		ft_print_di(opt, buffer, hours);
	if (minutes || hours)
	{
		if (hours)
			ft_in_buff(buffer, ':');
		ft_print_di(opt, buffer, minutes);
	}
	if (sec || minutes || hours)
	{
		if (minutes || hours)
			ft_in_buff(buffer, ':');
		ft_print_di(opt, buffer, sec);
	}
}
