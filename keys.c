/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntothmur <ntothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:20:41 by ntothmur          #+#    #+#             */
/*   Updated: 2019/10/19 14:24:40 by ntothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		keys(int key, t_fdf *fdf)
{
	if (key == KEY_ESC)
		exit(0);
	else if (key == KEY_MINUS || key == KEY_PLUS)
		zoom(key, fdf);
	else if (key == KEY_W || key == KEY_ARROW_UP
			|| key == KEY_A || key == KEY_ARROW_LEFT
			|| key == KEY_S || key == KEY_ARROW_DOWN
			|| key == KEY_D || key == KEY_ARROW_RIGHT
			|| key == KEY_Q || key == KEY_E)
		rotate(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		change_projection(key, fdf);
	return (0);
}
