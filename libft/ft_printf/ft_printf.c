/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 16:37:31 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/19 16:42:55 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_handle_other(t_options *opt, t_buff *buffer, va_list ap)
{
	if (opt->spec == 'c' && opt->length != LEN_L)
		ft_print_c(opt, buffer, (unsigned char)va_arg(ap, int));
	else if (opt->spec == 'C' || (opt->spec == 'c' && opt->length == LEN_L))
		ft_print_lc(opt, buffer, (wchar_t)va_arg(ap, wint_t));
	else if (opt->spec == 's' && opt->length != LEN_L)
		ft_print_s(opt, buffer, va_arg(ap, char*));
	else if (opt->spec == 'S' || (opt->spec == 's' && opt->length == LEN_L))
		ft_print_ls(opt, buffer, va_arg(ap, wchar_t*));
	else if (opt->spec == 'f' && opt->length == LEN_LL)
		ft_parse_lfnum(opt, buffer, va_arg(ap, long double), ft_print_f);
	else if (opt->spec == 'f' || opt->spec == 'F')
		ft_parse_fnum(opt, buffer, va_arg(ap, double), ft_print_f);
	else if (opt->spec == 'e' && opt->length == LEN_LL)
		ft_parse_lfnum(opt, buffer, va_arg(ap, long double), ft_print_e);
	else if (opt->spec == 'e' || opt->spec == 'E')
		ft_parse_fnum(opt, buffer, va_arg(ap, double), ft_print_e);
	else if (opt->spec == 'p')
		ft_print_p(opt, buffer, va_arg(ap, void*));
	else if (opt->spec == 'r')
		ft_print_r(opt, buffer, va_arg(ap, char*));
	else if (opt->spec == 'k')
		ft_print_k(opt, buffer, va_arg(ap, unsigned long long));
	else
		return (0);
	return (1);
}

int		ft_handle_num(t_options *opt, t_buff *buffer, va_list ap)
{
	if (opt->spec == 'd' || opt->spec == 'i' || opt->spec == 'D')
		ft_parse_num(opt, buffer, va_arg(ap, long long));
	else if (opt->spec == 'u' || opt->spec == 'U')
		ft_parse_unum(opt, buffer, va_arg(ap, unsigned long long));
	else if (opt->spec == 'o' || opt->spec == 'O')
	{
		opt->base = 8;
		ft_parse_unum(opt, buffer, va_arg(ap, unsigned long long));
	}
	else if (opt->spec == 'x' || opt->spec == 'X')
	{
		opt->base = 16;
		if (opt->spec == 'x')
			opt->flags |= F_LOWER;
		ft_parse_unum(opt, buffer, va_arg(ap, unsigned long long));
	}
	else if (opt->spec == 'b')
	{
		opt->base = 2;
		ft_parse_unum(opt, buffer, va_arg(ap, unsigned long long));
	}
	else
		return (0);
	return (1);
}

void	ft_handle_spec(t_options *opt, t_buff *buffer, va_list ap)
{
	if (ft_handle_num(opt, buffer, ap))
		return ;
	else if (ft_handle_other(opt, buffer, ap))
		return ;
	else if (opt->spec)
		ft_print_rand(opt, buffer);
}

void	ft_set_options(t_options *opt, const char **format, va_list ap)
{
	char	*temp;

	opt->flags = 0;
	opt->width = -1;
	opt->prec = -1;
	opt->length = 0;
	opt->base = 10;
	opt->spec = 0;
	while (**format)
	{
		temp = (char*)*format;
		ft_set_flags(format, opt);
		ft_set_width(format, opt, ap);
		ft_set_prec(format, opt, ap);
		ft_set_length(format, opt);
		if (ft_set_spec(**format, opt) || temp == *format)
		{
			if (**format)
				(*format)++;
			break ;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_options	opt;
	t_buff		buffer;

	va_start(ap, format);
	ft_set_buff(&buffer);
	while (*format)
	{
		if (*format != '%')
			ft_in_buff(&buffer, *format++);
		else
		{
			format++;
			ft_set_options(&opt, &format, ap);
			ft_handle_spec(&opt, &buffer, ap);
		}
	}
	va_end(ap);
	if (buffer.i)
		ft_out_buff(&buffer);
	return (buffer.len);
}
