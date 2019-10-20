/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntothmur <ntothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:10:16 by ntothmur          #+#    #+#             */
/*   Updated: 2019/10/20 18:36:45 by ntothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *s)
{
	if (errno == 0)
		ft_putendl_fd(s, 2);
	else
		perror(s);
	exit(1);
}

void	ft_init(t_mlx_fdf *mlx, t_map *map)
{
	map->projection = PARALLEL;
	map->angle_x = 0;
	map->angle_y = 0;
	map->angle_z = 0;
	map->zoom = 0;
	map->x_offset = 0;
	map->y_offset = 0;
	if (!(mlx->mlx_ptr = mlx_init()))
		ft_error(ERROR_MLX_INIT);
	if (!(mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 1000, 1000, "FDF")))
		ft_error(ERROR_MLX_NEW_WIN);
	if (!(mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, 1000, 1000)))
		ft_error(ERROR_MLX_NEW_IMG);
	if (!(mlx->data_addr = (char*)mlx_get_data_addr(mlx->img_ptr,
	&mlx->bits_per_pixel, &mlx->size_line, &mlx->endian)))
		ft_error(ERROR_MLX_GET_DATA);
}
