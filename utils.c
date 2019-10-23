/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:10:16 by ntothmur          #+#    #+#             */
/*   Updated: 2019/10/23 20:55:39 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_error(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void		ft_init(t_fdf *fdf)
{
	fdf->map = (t_map*)malloc(sizeof(t_map));
	fdf->mlx = (t_mlx_fdf*)malloc(sizeof(t_mlx_fdf));
	fdf->coords_arr = (t_coords_arr*)malloc(sizeof(t_coords_arr));
	fdf->coords_arr->size = 128;
	fdf->coords_arr->coords = (t_coords**)malloc(sizeof(t_coords*) * \
												fdf->coords_arr->size);
	fdf->coords_arr->maxz = 0;
	fdf->coords_arr->minz = 0;
	fdf->map->projection = PARALLEL;
	fdf->map->angle_x = 0;
	fdf->map->angle_y = 0;
	fdf->map->angle_z = 0;
	fdf->map->zoom = 0;
	fdf->map->x_offset = 0;
	fdf->map->y_offset = 0;
	if (!(fdf->mlx->mlx_ptr = mlx_init()))
		ft_error(ERROR_MLX_INIT);
	if (!(fdf->mlx->win_ptr = mlx_new_window(fdf->mlx->mlx_ptr, WIDTH, \
											HEIGHT, "FDF")))
		ft_error(ERROR_MLX_NEW_WIN);
	if (!(fdf->mlx->img_ptr = mlx_new_image(fdf->mlx->mlx_ptr, WIDTH, HEIGHT)))
		ft_error(ERROR_MLX_NEW_IMG);
	if (!(fdf->mlx->data_addr = mlx_get_data_addr(fdf->mlx->img_ptr,
		&fdf->mlx->bits_per_pixel, &fdf->mlx->size_line, &fdf->mlx->endian)))
		ft_error(ERROR_MLX_GET_DATA);
}

t_coords	*ft_create_point(int x, int y, int z, int color)
{
	t_coords	*point;

	point = (t_coords*)malloc(sizeof(t_coords));
	point->x = x;
	point->y = y;
	point->z = z;
	point->color = color;
	return (point);
}
