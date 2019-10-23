/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:06:46 by ntothmur          #+#    #+#             */
/*   Updated: 2019/10/23 20:53:14 by afalmer-         ###   ########.fr       */
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
# include "mlx.h"

# define ERROR_USAGE		"Usage: ./fdf *map_file*"
# define ERROR_MAP			"Incorrect map file"
# define ERROR_MAP_READING	"Reading error"
# define ERROR_MAP_OPEN		"Open error"
# define ERROR_MAP_COUNT	"Count error"
# define ERROR_MAP_VALIDATE	"Validate error"
# define ERROR_MLX_INIT		"Mlx init error"
# define ERROR_MLX_NEW_WIN	"Mlx new window error"
# define ERROR_MLX_NEW_IMG	"Mlx new image error"
# define ERROR_MLX_GET_DATA	"Mlx get data addr error"

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

# define WIDTH 1920
# define HEIGHT 1080

typedef enum
{
	ISO,
	PARALLEL
}	t_projection;

typedef struct			s_coords
{
	int					x;
	int					y;
	int					z;
	int					color;
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

typedef struct			s_coords_arr
{
	t_coords			**coords;
	size_t				size;
	int					minz;
	int					maxz;
}						t_coords_arr;

typedef struct			s_map
{
	t_projection		projection;
	int					width;
	int					height;
	double				angle_x;
	double				angle_y;
	double				angle_z;
	int					zoom;
	int					x_offset;
	int					y_offset;
}						t_map;

typedef struct			s_fdf
{
	t_map				*map;
	t_mlx_fdf			*mlx;
	t_coords_arr		*coords_arr;
}						t_fdf;

typedef struct			s_draw
{
	int					delta_x;
	int					delta_y;
	int					sign_x;
	int					sign_y;
	int					err;
	int					err2;
	t_coords			temp;
}						t_draw;

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
void					ft_init(t_fdf *fdf);
void					ft_draw_map(t_fdf *fdf);
int						ft_keys(int key, t_fdf *fdf);
void					ft_draw(t_fdf *fdf);
void					ft_menu(t_fdf *fdf);
t_coords				*ft_create_point(int x, int y, int z, int color);
int						ft_get_color(t_coords *curr, t_coords *start, \
									t_coords *end);
int						ft_get_gradient(int z, t_coords_arr *coords_arr);
void					ft_read_map(char *filename, t_fdf *fdf);

#endif
