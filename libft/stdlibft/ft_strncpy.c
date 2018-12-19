/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 21:35:29 by imaltsev          #+#    #+#             */
/*   Updated: 2017/07/31 12:48:22 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	count;

	count = 0;
	while ((count != len) && (src[count] != '\0'))
	{
		dst[count] = src[count];
		count++;
	}
	while (count != len)
		dst[count++] = '\0';
	return (dst);
}
