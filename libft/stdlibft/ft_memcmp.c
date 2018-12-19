/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 14:24:23 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/05 14:24:25 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	unsigned char	*str_x;
	unsigned char	*str_y;

	i = 0;
	str_x = (unsigned char*)s1;
	str_y = (unsigned char*)s2;
	while (n--)
	{
		if (str_x[i] != str_y[i])
			return (str_x[i] - str_y[i]);
		i++;
	}
	return (0);
}
