/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:56:38 by ntothmur          #+#    #+#             */
/*   Updated: 2019/10/23 20:15:02 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu(t_fdf *fdf)
{
	int		i;

	i = 0;
	mlx_string_put(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, \
					80, i += 20, 0x006400, "How to Use");
	mlx_string_put(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, \
					15, i += 35, 0x7FFFD4, "Zoom: +/-");
	mlx_string_put(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, \
					15, i += 30, 0x7FFFD4, "Rotate:");
	mlx_string_put(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, \
					55, i += 25, 0x7FFFD4, "X-Axis - W/S, UP/DOWN");
	mlx_string_put(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, \
					55, i += 25, 0x7FFFD4, "Y-Axis - A/D, LEFT/RIGHT");
	mlx_string_put(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, \
					55, i += 25, 0x7FFFD4, "Z-Axis - W/E");
	mlx_string_put(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, \
					15, i += 30, 0x7FFFD4, "Projection");
	mlx_string_put(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, \
					55, i += 25, 0x7FFFD4, "ISO: I Key");
	mlx_string_put(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, \
					55, i += 25, 0x7FFFD4, "Parallel: P Key");
}
