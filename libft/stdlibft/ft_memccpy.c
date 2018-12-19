/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 15:51:50 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/05 15:51:54 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n > 0 && *s != (unsigned char)c)
	{
		*d++ = *s++;
		n--;
	}
	if (n > 0)
	{
		*d++ = *s++;
		return ((void *)d);
	}
	return (NULL);
}
