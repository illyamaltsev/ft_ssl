/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 16:13:21 by imaltsev          #+#    #+#             */
/*   Updated: 2018/02/05 16:13:22 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_wstrlen(wchar_t *wstr)
{
	size_t	i;
	size_t	count;
	int		size;

	i = 0;
	count = 0;
	while (wstr[i] != L'\0')
	{
		size = ft_bitsize(wstr[i]);
		if (size <= 7)
			count = count + 1;
		else if (size <= 11)
			count = count + 2;
		else if (size <= 16)
			count = count + 3;
		else
			count = count + 4;
		i++;
	}
	return (count);
}

char		*ft_wstrtoa(wchar_t *wstr)
{
	int		i;
	int		b;
	char	*str;

	i = 0;
	b = 0;
	str = ft_strnew(ft_wstrlen(wstr));
	while (wstr[i] != L'\0')
	{
		b = b + ft_wchtoa(wstr[i], str, b);
		i++;
	}
	return (str);
}
