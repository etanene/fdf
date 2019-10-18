/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_manage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/10 19:30:33 by aleksandr         #+#    #+#             */
/*   Updated: 2019/02/10 19:59:40 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_buff(t_buff *buffer)
{
	int		i;

	i = 0;
	while (i < MAX_LEN)
		buffer->buff[i++] = '\0';
	buffer->i = 0;
	buffer->len = 0;
}

void	ft_out_buff(t_buff *buffer)
{
	write(1, buffer->buff, buffer->i);
	buffer->len += buffer->i;
	buffer->i = 0;
}

void	ft_in_buff(t_buff *buffer, unsigned char c)
{
	buffer->buff[buffer->i++] = c;
	if (buffer->i == MAX_LEN - 1)
		ft_out_buff(buffer);
}
