/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntothmur <ntothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:43:49 by afalmer-          #+#    #+#             */
/*   Updated: 2019/10/22 14:23:21 by ntothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_coords *coords, t_fdf *fdf)
{
	int	i;

	i = (coords->x * fdf->mlx->bits_per_pixel / 8 * fdf->map->zoom) + (coords->y * fdf->mlx->size_line * fdf->map->zoom);
	if (coords->x >= 0 && coords->x < WIDTH && coords->y >= 0 && coords->y < HEIGHT)
	{
		fdf->mlx->data_addr[i] = coords->color;
		fdf->mlx->data_addr[i + 1] = coords->color >> 8;
		fdf->mlx->data_addr[i + 2] = coords->color >> 16;
		fdf->mlx->data_addr[i + 3] = 0;
	}
}

void	ft_draw_line(int x1, int y1, int x2, int y2)
{
	t_draw	draw;

	draw.deltaX = abs(x2 - x1);
	draw.deltaY = abs(y2 - y1);
	draw.signX = x2 > x1 ? 1 : -1;
	draw.signY = y2 > y1 ? 1 : -1;
	draw.err = draw.deltaX - draw.deltaY;
	// ft_put_pixel(x1, y2, );
}

// int		calculate_default_zoom(t_map *map)
// {

// }

void	ft_draw(t_fdf *fdf)
{
	t_coords	*temp;

	temp = fdf->coords;
	fdf->map->x_offset = 0 - (fdf->map->width / 2 * fdf->map->zoom) + (WIDTH / 2);
	fdf->map->y_offset = 0 - (fdf->map->height / 2 * fdf->map->zoom) + (HEIGHT / 2);
	mlx_clear_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr);

ft_printf("len: %d\n", ft_strlen(fdf->mlx->data_addr));
	bzero(fdf->mlx->data_addr, WIDTH * fdf->mlx->bits_per_pixel / 8 * HEIGHT);
	while (temp)
	{
		ft_put_pixel(temp, fdf);
		temp = temp->next;
	}
	mlx_put_image_to_window(fdf->mlx->mlx_ptr, fdf->mlx->win_ptr, fdf->mlx->img_ptr, fdf->map->x_offset, fdf->map->y_offset);
	ft_menu(fdf);
}

void	ft_draw_map(t_fdf *fdf)
{
	fdf->map->zoom = fmin((WIDTH / fdf->map->width / 2), (HEIGHT / fdf->map->height / 2));


	ft_draw(fdf);
	mlx_key_hook(fdf->mlx->win_ptr, ft_keys, fdf);
	mlx_loop(fdf->mlx->mlx_ptr);
}
