/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:11:18 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/08 17:11:20 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new_str;

	if ((new_str = (char *)malloc(sizeof(char) * size + 1)) == 0)
		return (NULL);
	ft_bzero(new_str, size + 1);
	return (new_str);
}
