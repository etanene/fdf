/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:58:07 by ntothmur          #+#    #+#             */
/*   Updated: 2019/10/19 18:39:22 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_rotate_x(int *y, int *z, double angle_x)
{
	int previous_y;

	previous_y = *y;
	*y = previous_y * cos(angle_x) + *z * sin(angle_x);
	*z = -previous_y * sin(angle_x) + *z * cos(angle_x);
}

void	ft_rotate_y(int *x, int *z, double angle_y)
{
	int previous_x;

	previous_x = *x;
	*x = previous_x * cos(angle_y) + *z * sin(angle_y);
	*z = -previous_x * sin(angle_y) + *z * cos(angle_y);
}

void	ft_rotate_z(int *x, int *y, double angle_z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(angle_z) - previous_y * sin(angle_z);
	*y = previous_x * sin(angle_z) + previous_y * cos(angle_z);
}

void	ft_iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}
