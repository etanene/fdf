/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_multiarr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 14:16:49 by afalmer-          #+#    #+#             */
/*   Updated: 2019/05/16 15:24:11 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_multiarr(char **arr)
{
	char	**temp;

	temp = arr;
	while (*temp)
	{
		free(*temp++);
	}
	free(arr);
}
