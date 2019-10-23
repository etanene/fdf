/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:34:53 by afalmer-          #+#    #+#             */
/*   Updated: 2019/10/23 21:10:05 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**ft_get_point(char *line_coords)
{
	char	**point;

	point = ft_strsplit(line_coords, ',');
	ft_str_toupper(point[1]);
	if (!ft_isnumber_base(point[0], 10) ||
			(point[1] && !ft_validate_color(point[1])))
		ft_error(ERROR_MAP_VALIDATE);
	return (point);
}

void	ft_add_coords(t_fdf *fdf, char **line_coords, int y)
{
	char		**point;
	int			x;
	int			size_line;
	int			z;

	x = 0;
	size_line = ft_count_arr(line_coords);
	while (*line_coords)
	{
		point = ft_get_point(*line_coords);
		if (y * size_line + x >= (int)fdf->coords_arr->size)
			fdf->coords_arr->coords = \
			ft_realloc((void**)&fdf->coords_arr->coords, &fdf->coords_arr->size,
			sizeof(*fdf->coords_arr->coords), fdf->coords_arr->size * 2);
		z = ft_atoi_base(point[0], 10);
		fdf->coords_arr->coords[y * size_line + x] = ft_create_point(x, y, z, \
								point[1] ? ft_atoi_base(point[1] + 2, 16) : -1);
		fdf->coords_arr->minz = fmin(fdf->coords_arr->minz, z);
		fdf->coords_arr->maxz = fmax(fdf->coords_arr->maxz, z);
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
	line_coords = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error(ERROR_MAP_OPEN);
	while (get_next_line(fd, &line) > 0)
	{
		line_coords = ft_get_coords_line(line);
		ft_strdel(&line);
		ft_add_coords(fdf, line_coords, y++);
		ft_free_multiarr(line_coords);
	}
	if (!line_coords)
		ft_error(ERROR_MAP_VALIDATE);
}
