/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:20:41 by ntothmur          #+#    #+#             */
/*   Updated: 2019/10/19 18:41:29 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_keys(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_MINUS || key == KEY_PLUS)
		ft_zoom(key, fdf);
	else if (key == KEY_W || key == KEY_ARROW_UP
			|| key == KEY_A || key == KEY_ARROW_LEFT
			|| key == KEY_S || key == KEY_ARROW_DOWN
			|| key == KEY_D || key == KEY_ARROW_RIGHT
			|| key == KEY_Q || key == KEY_E)
		ft_rotate(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		ft_change_projection(key, fdf);
	return (0);
}
