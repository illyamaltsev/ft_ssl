/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 16:30:16 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/03 16:30:17 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *end_c;

	end_c = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			end_c = (char *)s;
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return (end_c);
}
