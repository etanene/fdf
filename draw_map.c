/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:43:49 by afalmer-          #+#    #+#             */
/*   Updated: 2019/10/22 19:19:43 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_coords *coords, t_fdf *fdf)
{
	int	i;

	i = (coords->x * fdf->mlx->bits_per_pixel / 8) + (coords->y * fdf->mlx->size_line);
	if (coords->x >= 0 && coords->x < WIDTH && coords->y >= 0 && coords->y < HEIGHT)
	{
		fdf->mlx->data_addr[i] = coords->color;
		fdf->mlx->data_addr[i + 1] = coords->color >> 8;
		fdf->mlx->data_addr[i + 2] = coords->color >> 16;
		fdf->mlx->data_addr[i + 3] = 0;
	}
}

void	ft_draw_line(t_coords *point1, t_coords *point2, t_fdf *fdf)
{
	t_draw		draw;
	t_coords	*temp_point;

	draw.deltaX = abs(point2->x - point1->x);
	draw.deltaY = abs(point2->y - point1->y);
	draw.signX = point2->x > point1->x ? 1 : -1;
	draw.signY = point2->y  > point1->y  ? 1 : -1;
	draw.err = draw.deltaX - draw.deltaY;
	ft_put_pixel(point2, fdf);
	temp_point = ft_create_point(point1->x, point1->y, point1->z, point1->color);
	while (temp_point->x != point2->x || temp_point->y != point2->y)
	{
		ft_put_pixel(temp_point, fdf);
		draw.err2 = draw.err * 2;
		if (draw.err2 > -draw.deltaY)
		{
			draw.err -= draw.deltaY;
			temp_point->x += draw.signX;
		}
		if (draw.err2 < draw.deltaX)
		{
			draw.err += draw.deltaX;
			temp_point->y += draw.signY;
		}
	}
	free(point1);
	free(point2);
}

// int		calculate_default_zoom(t_map *map)
// {

// }

t_coords	*ft_calculate(t_coords *point, t_fdf *fdf)
{
	t_coords	*new;

	new = ft_create_point(point->x, point->y, point->z, point->color);
	new->x *= fdf->map->zoom;
	new->y *= fdf->map->zoom;
	new->z *= fdf->map->zoom;
	ft_rotate_x(&new->y, &new->z, fdf->map->angle_x);
	ft_rotate_y(&new->x, &new->z, fdf->map->angle_y);
	ft_rotate_z(&new->x, &new->y, fdf->map->angle_z);
	if (fdf->map->projection == ISO)
		ft_iso(&new->x, &new->y, new->z);
	fdf->map->x_offset = 0 - (fdf->map->width / 2 * fdf->map->zoom) + (WIDTH / 2);
	fdf->map->y_offset = 0 - (fdf->map->height / 2 * fdf->map->zoom) + (HEIGHT / 2);
	return (new);
}

void	ft_draw(t_fdf *fdf)
{
	int		x;
	int		y;

	mlx_clear_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr);
	ft_bzero(fdf->mlx->data_addr, WIDTH * fdf->mlx->bits_per_pixel / 8 * HEIGHT);
	x = 0;
	while (x < fdf->map->width)
	{
		y = 0;
		while (y < fdf->map->height)
		{
			if (x < fdf->map->width - 1)
				ft_draw_line(
					ft_calculate(fdf->coords_arr->coords[x + y * fdf->map->width], fdf),
					ft_calculate(fdf->coords_arr->coords[(x + 1) + y * fdf->map->width], fdf),
					fdf
				);
			if (y < fdf->map->height - 1)
				ft_draw_line(
					ft_calculate(fdf->coords_arr->coords[x + y * fdf->map->width], fdf),
					ft_calculate(fdf->coords_arr->coords[x + (y + 1) * fdf->map->width], fdf),
					fdf
				);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img_ptr, fdf->map->x_offset, fdf->map->y_offset);
	ft_menu(fdf);
}

void	ft_draw_map(t_fdf *fdf)
{
	fdf->map->zoom = fmin((WIDTH / fdf->map->width / 2), (HEIGHT / fdf->map->height / 2));
	fdf->map->x_offset = 0 - (fdf->map->width / 2 * fdf->map->zoom) + (WIDTH / 2);
	fdf->map->y_offset = 0 - (fdf->map->height / 2 * fdf->map->zoom) + (HEIGHT / 2);

	ft_draw(fdf);
	mlx_key_hook(fdf->mlx->win_ptr, ft_keys, fdf);
	mlx_loop(fdf->mlx->mlx_ptr);
}
