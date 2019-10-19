/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:28:58 by ntothmur          #+#    #+#             */
/*   Updated: 2019/10/19 18:42:09 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int key, t_fdf *fdf)
{
	if (key == KEY_MINUS)
		fdf->map->zoom--;
	if (key == KEY_PLUS)
		fdf->map->zoom++;
	if (fdf->map->zoom < 0)
		fdf->map->zoom = 1;
	// draw(fdf->map, fdf);
}

void	ft_rotate(int key, t_fdf *fdf)
{
	if (key == KEY_S || key == KEY_ARROW_DOWN)
		fdf->map->angle_x += 0.05;
	else if (key == KEY_W || key == KEY_ARROW_UP)
		fdf->map->angle_x -= 0.05;
	else if (key == KEY_A || key == KEY_ARROW_LEFT)
		fdf->map->angle_y -= 0.05;
	else if (key == KEY_D || key == KEY_ARROW_RIGHT)
		fdf->map->angle_y += 0.05;
	else if (key == KEY_Q)
		fdf->map->angle_z += 0.05;
	else if (key == KEY_E)
		fdf->map->angle_z -= 0.05;
	// draw(fdf->map, fdf);
}

void	ft_change_projection(int key, t_fdf *fdf)
{
	fdf->map->angle_x = 0;
	fdf->map->angle_y = 0;
	fdf->map->angle_z = 0;
	if (key == KEY_I)
		fdf->map->projection = ISO;
	else if (key == KEY_P)
		fdf->map->projection = PARALLEL;
	// draw(fdf->map, fdf);
}

void	ft_close(void)
{
	exit(0);
}
