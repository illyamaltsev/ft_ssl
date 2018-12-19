/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corect_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:26:02 by imaltsev          #+#    #+#             */
/*   Updated: 2018/01/15 19:26:03 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_corect_plus_and_space(char *str, t_spcf spcf)
{
	char	*new;

	if (spcf.plus && str[0] != '-')
	{
		new = ft_strjoin("+", str);
		free(str);
		return (new);
	}
	if (spcf.space && str[0] != '-' && str[0] != '+')
	{
		new = ft_strjoin(" ", str);
		free(str);
		return (new);
	}
	return (str);
}

char	*ft_corect_sharp(char *str, t_spcf spcf, unsigned int size)
{
	char	*new;
	int		point;

	point = 0;
	new = NULL;
	if (spcf.conversion == 'o' && spcf.zero
		&& !ft_memchr(spcf.spcf, '.', spcf.size)
		&& spcf.precision == -1 && spcf.width > size + 1 && !spcf.minus)
		point = 1;
	if (ft_memchr("xX", spcf.conversion, 2) && spcf.zero
		&& !ft_memchr(spcf.spcf, '.', spcf.size)
		&& spcf.precision == -1 && spcf.width > size + 2 && !spcf.minus)
		point = 2;
	if (spcf.conversion == 'o')
		new = ft_strjoin("0", str + point);
	else if (spcf.conversion == 'x' || spcf.conversion == 'X'
		|| spcf.conversion == 'p')
		new = ft_strjoin("0x", str + point);
	if (new)
	{
		free(str);
		return (new);
	}
	else
		return (str);
}

char	*ft_corect(char *str, t_spcf spcf, int point)
{
	int size;

	if ((str[0] == '0' && ft_memchr("xXo", spcf.conversion, 3))
		|| (str[0] == '\0' && ft_memchr("xX", spcf.conversion, 2)))
		point = 1;
	if (ft_memchr("di", spcf.conversion, 3) && (spcf.plus || spcf.space))
		str = ft_corect_plus_and_space(str, spcf);
	if (spcf.precision != -1)
		str = ft_corect_precision(str, spcf);
	if (spcf.sharp && point == 0 && (spcf.minus || !spcf.zero ||
	(spcf.zero && (int)spcf.width > spcf.precision && (spcf.precision != -1
		|| (spcf.precision == -1 && ft_memchr(spcf.spcf, '.', spcf.size))))))
	{
		point = 1;
		str = ft_corect_sharp(str, spcf, 0);
	}
	size = ft_strlen(str);
	if (ft_strlen(str) < spcf.width)
		str = ft_corect_width(str, spcf, -1);
	if (spcf.sharp && point == 0 && !spcf.minus && spcf.zero)
		str = ft_corect_sharp(str, spcf, size);
	if (spcf.conversion == 'X')
		str = ft_gobig(str);
	return (str);
}
