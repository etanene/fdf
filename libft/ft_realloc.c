/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:09:22 by afalmer-          #+#    #+#             */
/*   Updated: 2019/10/22 16:21:17 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void **mem, size_t *size, int elem_size, size_t new_size)
{
	void	*temp;

	if (!(temp = malloc(new_size * elem_size)))
		return (NULL);
	temp = ft_memcpy(temp, *mem, *size * elem_size);
	free(*mem);
	*mem = temp;
	*size = new_size;
	return (*mem);
}
