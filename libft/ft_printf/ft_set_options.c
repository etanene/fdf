/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 20:27:24 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/19 18:36:38 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_flags(const char **format, t_options *opt)
{
	while (**format)
	{
		if (**format == '-')
			opt->flags |= F_MINUS;
		else if (**format == '+')
			opt->flags |= F_PLUS;
		else if (**format == ' ')
			opt->flags |= F_SP;
		else if (**format == '#')
			opt->flags |= F_SHARP;
		else if (**format == '0')
			opt->flags |= F_NULL;
		else
			break ;
		(*format)++;
	}
}

void	ft_set_width(const char **format, t_options *opt, va_list ap)
{
	if (**format >= '0' && **format <= '9')
	{
		opt->width = ft_atoi(*format);
		*format += ft_unumlen(opt->width, 10);
	}
	else if (**format == '*')
	{
		opt->width = va_arg(ap, int);
		if (opt->width < 0)
		{
			opt->flags |= F_MINUS;
			opt->width = -opt->width;
		}
		(*format)++;
	}
}

void	ft_set_prec(const char **format, t_options *opt, va_list ap)
{
	if (**format == '.')
	{
		(*format)++;
		if (**format >= '0' && **format <= '9')
		{
			opt->prec = ft_atoi(*format);
			*format += ft_unumlen(opt->prec, 10);
		}
		else if (**format == '*')
		{
			opt->prec = va_arg(ap, int);
			(*format)++;
		}
		else
			opt->prec = 0;
	}
}

void	ft_set_length(const char **format, t_options *opt)
{
	while (**format)
	{
		if (**format == 'h' && *(*format + 1) == 'h' && (*format)++)
			opt->length = opt->length < LEN_HH ? LEN_HH : opt->length;
		else if (**format == 'h' && opt->length != LEN_HH)
			opt->length = opt->length < LEN_H ? LEN_H : opt->length;
		else if (**format == 'l' && *(*format + 1) == 'l' && (*format)++)
			opt->length = opt->length < LEN_LL ? LEN_LL : opt->length;
		else if (**format == 'l' && opt->length != LEN_LL)
			opt->length = opt->length < LEN_L ? LEN_L : opt->length;
		else if (**format == 'L')
			opt->length = opt->length < LEN_LL ? LEN_LL : opt->length;
		else if (**format == 't')
			opt->length = opt->length < LEN_TIME ? LEN_TIME : opt->length;
		else if (**format == 'z')
			opt->length = opt->length < LEN_Z ? LEN_Z : opt->length;
		else if (**format == 'j')
			opt->length = opt->length < LEN_J ? LEN_J : opt->length;
		else
			break ;
		(*format)++;
	}
}

int		ft_set_spec(char c, t_options *opt)
{
	char *nospec;

	nospec = "-+ #0*.hlLtzj";
	if (!(c >= '0' && c <= '9'))
	{
		while (*nospec)
		{
			if (c == *nospec)
				return (0);
			nospec++;
		}
		opt->spec = c;
		return (1);
	}
	return (0);
}
