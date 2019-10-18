/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:21:47 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/12 17:13:51 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*res;
	char	*p;

	if ((res = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)) == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	p = res;
	while (*s1)
		*p++ = *s1++;
	*p = '\0';
	return (res);
}
