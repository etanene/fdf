/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:13:10 by afalmer-          #+#    #+#             */
/*   Updated: 2019/10/22 20:44:32 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	ft_add_coords(t_fdf *fdf, char **line_coords, int y)
{
	char		**point;
	int			x;
	int			size_line;

	x = 0;
	size_line = ft_count_arr(line_coords);
	while (*line_coords)
	{
		point = ft_strsplit(*line_coords, ',');
		ft_str_toupper(point[1]);
		if (!ft_isnumber_base(point[0], 10) ||
			(point[1] && !ft_validate_color(point[1])))
			ft_error(ERROR_MAP_VALIDATE);
		if (y * size_line + x >= (int)fdf->coords_arr->size)
			fdf->coords_arr->coords = ft_realloc((void**)&fdf->coords_arr->coords,
										&fdf->coords_arr->size,
										sizeof(*fdf->coords_arr->coords),
										fdf->coords_arr->size * 2);
		fdf->coords_arr->coords[y * size_line + x] = ft_create_point(x, y, ft_atoi_base(point[0], 10), point[1] ? ft_atoi_base(point[1] + 2, 16) : 0xFFFFFF);
		x++;
		line_coords++;
		ft_free_multiarr(point);
	}
	fdf->map->height = y + 1;
	fdf->map->width = x;
}

char	**ft_get_coords_line(char *line)
{
	static int	count;
	int			curr_count;
	char		**coords;

	coords = ft_strsplit(line, ' ');
	curr_count = ft_count_arr(coords);
	if (count != 0 && count != curr_count)
		ft_error(ERROR_MAP_COUNT);
	count = curr_count;
	return (coords);
}

void	ft_read_map(char *filename, t_fdf *fdf)
{
	int			fd;
	char		*line;
	char		**line_coords;
	int			y;

	y = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error(ERROR_MAP_OPEN);
	while (get_next_line(fd, &line) > 0)
	{
		line_coords = ft_get_coords_line(line);
		ft_strdel(&line);
		ft_add_coords(fdf, line_coords, y++);
		ft_free_multiarr(line_coords);
	}
}

void ft_print_map(t_coords **map, size_t size)
{
	size_t		i;

	i = 0;
	ft_printf("hello\n");
	while (i < size)
	{
		ft_printf("ind: %d\n", i);
		ft_printf("x: %d y: %d z: %d color: %d\n", map[i]->x, map[i]->y, map[i]->z, map[i]->color);
		i++;
	}
}

void	ft_transform(t_fdf *fdf)
{
	t_coords **coords;
	int		x;
	int		y;

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

int		main(int ac, char **av)
{
	t_fdf		fdf;

	if (ac < 2)
		ft_error(ERROR_USAGE);
	ft_init(&fdf);
	ft_read_map(av[1], &fdf);
	ft_transform(&fdf);
	// ft_printf("width: %d height: %d\n", fdf.map->width, fdf.map->height);
	ft_draw_map(&fdf);
	// ft_print_map(fdf.coords_arr->coords, fdf.coords_arr->size);
	return (0);
}
