/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_options.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 14:23:54 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/11 15:54:49 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_width(t_buff *buffer, int *width, char c)
{
	while ((*width)-- > 0)
	{
		ft_in_buff(buffer, c);
	}
}

void	ft_print_prec(t_buff *buffer, int prec, int len)
{
	while (len < prec--)
	{
		ft_in_buff(buffer, '0');
	}
}

void	ft_print_sharp(t_buff *buffer, t_options *opt)
{
	if (opt->base == 16)
	{
		ft_in_buff(buffer, '0');
		ft_in_buff(buffer, 'X' | (opt->flags & F_LOWER));
	}
	else if (opt->base == 8)
		ft_in_buff(buffer, '0');
	else if (opt->base == 2)
	{
		ft_in_buff(buffer, '0');
		ft_in_buff(buffer, 'b');
	}
}
