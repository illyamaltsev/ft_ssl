/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:54:33 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/10 18:54:35 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len(const char *c)
{
	size_t		i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		x;
	size_t		n;
	size_t		c;

	x = 0;
	c = len(src);
	if (size >= len(dst))
		n = len(dst);
	else
		n = size;
	while (dst[x] != '\0')
		x++;
	if (size == 0)
		return (n + c);
	while ((x != (n + c)) && (x < size - 1) && (*src != '\0'))
		dst[x++] = *src++;
	dst[x] = '\0';
	return (n + c);
}
