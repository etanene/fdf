/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:13:10 by afalmer-          #+#    #+#             */
/*   Updated: 2019/10/24 16:22:22 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_transform(t_fdf *fdf)
{
	t_coords	**coords;
	int			x;
	int			y;

	coords = fdf->coords_arr->coords;
	x = 0;
	while (x < fdf->map->width)
	{
		y = 0;
		while (y < fdf->map->height)
		{
			coords[x + y * fdf->map->width]->x -= fdf->map->width / 2;
			coords[x + y * fdf->map->width]->y -= fdf->map->height / 2;
			y++;
		}
		x++;
	}
}

void	ft_draw_map(t_fdf *fdf)
{
	fdf->map->zoom = fmin((WIDTH / fdf->map->width / 3), \
						(HEIGHT / fdf->map->height / 3));
	ft_draw(fdf);
	mlx_hook(fdf->mlx->win_ptr, 2, 0, ft_keys, fdf);
	mlx_loop(fdf->mlx->mlx_ptr);
}

int		main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac != 2)
		ft_error(ERROR_USAGE);
	ft_init(&fdf);
	ft_read_map(av[1], &fdf);
	ft_init_mlx(&fdf);
	ft_transform(&fdf);
	ft_draw_map(&fdf);
	return (0);
}
