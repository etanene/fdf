/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:13:10 by afalmer-          #+#    #+#             */
/*   Updated: 2019/10/19 20:31:05 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_add_coords(t_coords **coords, char **line_coords, int y)
{
	t_coords	*new;
	char		**point;
	int			x;

	x = 0;
	while (*line_coords)
	{
		point = ft_strsplit(*line_coords, ',');
		ft_str_toupper(point[1]);
		new = (t_coords*)malloc(sizeof(t_coords));
		if (!ft_isnumber_base(point[0], 10) ||
			(point[1] && !ft_validate_color(point[1])))
			ft_error(ERROR_MAP_VALIDATE);
		new->x = x++;
		new->y = y;
		new->z = ft_atoi_base(point[0], 10);
		new->color = point[1] ? ft_atoi_base(point[1] + 2, 16) : 0;
		new->next = *coords;
		*coords = new;
		line_coords++;
	}
	ft_free_multiarr(point);
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

t_coords *ft_read_map(char *filename)
{
	int			fd;
	char		*line;
	t_coords	*coords;
	char		**line_coords;
	int			y;

	y = 0;
	coords = NULL;
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error(ERROR_MAP_OPEN);
	while (get_next_line(fd, &line) > 0)
	{
		line_coords = ft_get_coords_line(line);
		ft_strdel(&line);
		ft_add_coords(&coords, line_coords, y++);
		ft_free_multiarr(line_coords);
	}
	return (coords);
}

void ft_print_map(t_coords *map)
{
	while (map)
	{
		ft_printf("x: %d y: %d z: %d color: %d\n", map->x, map->y, map->z, map->color);
		map = map->next;
	}
}

int		main(int ac, char **av)
{
	t_coords	*map;

	if (ac < 2)
		ft_error(ERROR_USAGE);
	map = ft_read_map(av[1]);
	ft_print_map(map);
	return (0);
}
