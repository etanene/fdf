/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntothmur <ntothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:06:46 by ntothmur          #+#    #+#             */
/*   Updated: 2019/10/18 18:41:31 by ntothmur         ###   ########.fr       */
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

# define ERROR_USAGE		"Usage: ./fdf *map_file*"
# define ERROR_MAP			"Incorrect map file"
# define ERROR_MAP_READING	"Reading error"

typedef struct			s_coords
{
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

typedef struct			s_map
{
	t_coords			**coord_arr;
	int					width;
	int					height;
}						t_map;

#endif
