/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:06:46 by ntothmur          #+#    #+#             */
/*   Updated: 2019/10/19 20:28:05 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include <math.h>

# define ERROR_USAGE		"Usage: ./fdf *map_file*"
# define ERROR_MAP			"Incorrect map file"
# define ERROR_MAP_READING	"Reading error"
# define ERROR_MAP_OPEN		"Open error"
# define ERROR_MAP_COUNT	"Count error"
# define ERROR_MAP_VALIDATE	"Validate error"

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_I 34
# define KEY_P 35
# define KEY_MINUS 27
# define KEY_PLUS 24
# define KEY_ARROW_UP 126
# define KEY_ARROW_DOWN 125
# define KEY_ARROW_LEFT 123
# define KEY_ARROW_RIGHT 124

typedef enum
{
	ISO,
	PARALLEL
}						t_projection;

typedef struct			s_coords
{
	int					x;
	int					y;
	int					z;
	int					color;
	struct s_coords		*next;
}						t_coords;

typedef struct			s_mlx_fdf
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	char				*data_addr;
	int					size_line;
	int					endian;
	int					bits_per_pixel;
}						t_mlx_fdf;

typedef struct			s_map
{
	t_coords			**coord_arr;
	t_projection		projection;
	int					width;
	int					height;
	double				angle_x;
	double				angle_y;
	double				angle_z;
	int					zoom;
}						t_map;

typedef struct 			s_fdf
{
	t_map				*map;
	t_mlx_fdf			mlx;
}						t_fdf;



void					ft_error(char *s);
void					ft_rotate_x(int *y, int *z, double angle_x);
void					ft_rotate_y(int *x, int *z, double angle_y);
void					ft_rotate_z(int *x, int *y, double angle_z);
void					ft_iso(int *x, int *y, int z);
void					ft_zoom(int key, t_fdf *fdf);
void					ft_rotate(int key, t_fdf *fdf);
void					ft_change_projection(int key, t_fdf *fdf);
void					ft_close(void);
int						ft_validate_color(char *str);

#endif
