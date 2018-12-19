/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 10:01:45 by imaltsev          #+#    #+#             */
/*   Updated: 2017/08/01 22:07:12 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	char	*tmp;

	tmp = dest;
	while (*tmp != '\0')
	{
		tmp++;
	}
	while (*src != '\0' && nb > 0)
	{
		*tmp = *src;
		tmp++;
		src++;
		nb--;
	}
	*tmp = '\0';
	return (dest);
}
