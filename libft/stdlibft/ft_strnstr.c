/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 13:39:45 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/05 13:39:46 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int i;
	int j;

	i = 0;
	if (to_find[0] == '\0')
		return ((char *)str);
	while (str[i] != '\0' && len > 0)
	{
		j = 0;
		while (str[i + j] != '\0' && to_find[j] == str[i + j] && len > 0)
		{
			if (to_find[j + 1] == '\0')
			{
				return ((char *)str + i);
			}
			j++;
			len--;
		}
		len = len + j;
		i++;
		len--;
	}
	return (NULL);
}
