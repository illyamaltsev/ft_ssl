/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtulchiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:42:16 by rtulchiy          #+#    #+#             */
/*   Updated: 2017/11/13 14:42:18 by rtulchiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_array(int fd)
{
	char	tmp[4096];
	char	*str;
	int		i;

	i = 0;
	while (i < 4096 && read(fd, &tmp[i], 1))
		i++;
	if (i == 4096)
		return (NULL);
	tmp[i] = 0;
	if (!(str = (char*)ft_memalloc((i + 1) * sizeof(char))))
		return (0);
	i = -1;
	while (tmp[++i])
		str[i] = tmp[i];
	str[i] = '\0';
	return (str);
}
