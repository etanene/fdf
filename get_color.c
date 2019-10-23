/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:36:18 by afalmer-          #+#    #+#             */
/*   Updated: 2019/10/23 20:13:30 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	ft_percent(int start, int end, int curr)
{
	double	placement;
	double	distance;

	placement = curr - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		ft_get_light(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int		ft_get_color(t_coords *curr, t_coords *start, t_coords *end)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (curr->color == end->color)
		return (curr->color);
	if (abs(start->x - end->x) > abs(start->y - end->y))
		percent = ft_percent(start->x, end->x, curr->x);
	else
		percent = ft_percent(start->y, end->y, curr->y);
	red = ft_get_light((start->color >> 16) & 0xFF, \
						(end->color >> 16) & 0xFF, percent);
	green = ft_get_light((start->color >> 8) & 0xFF, \
						(end->color >> 8) & 0xFF, percent);
	blue = ft_get_light(start->color & 0xFF, end->color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

int		ft_get_gradient(int z, t_coords_arr *coords_arr)
{
	double	percent;

	percent = ft_percent(coords_arr->minz, coords_arr->maxz, z);
	if (percent < 0.2)
		return (0x0000CD);
	else if (percent < 0.4)
		return (0x00BFFF);
	else if (percent < 0.6)
		return (0xF0E68C);
	else if (percent < 0.8)
		return (0xFFA500);
	else
		return (0xB22222);
}
