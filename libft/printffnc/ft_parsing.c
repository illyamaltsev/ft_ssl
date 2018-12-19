/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:00:24 by imaltsev          #+#    #+#             */
/*   Updated: 2018/01/20 15:00:25 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_spcf	ft_find_modifier(t_spcf spcf)
{
	if (ft_memchr("CSDOU", spcf.conversion, 5))
	{
		spcf.conversion = spcf.conversion + 32;
		spcf.modifier = 'l';
	}
	else if (ft_memchr(spcf.spcf, 'z', spcf.size))
		spcf.modifier = 'z';
	else if (ft_memchr(spcf.spcf, 'j', spcf.size))
		spcf.modifier = 'j';
	else if (ft_strstr(spcf.spcf, "ll"))
		spcf.modifier = 'L';
	else if (ft_memchr(spcf.spcf, 'l', spcf.size))
		spcf.modifier = 'l';
	else if (ft_strstr(spcf.spcf, "hh"))
		spcf.modifier = 'H';
	else if (ft_memchr(spcf.spcf, 'h', spcf.size))
		spcf.modifier = 'h';
	else
		spcf.modifier = 0;
	return (spcf);
}

int		ft_find_width(t_spcf spcf)
{
	int width;

	while ((*spcf.spcf < '1' || *spcf.spcf > '9')
		&& *spcf.spcf != '\0' && *spcf.spcf != '.')
		spcf.spcf++;
	width = ft_atoi(spcf.spcf);
	if (width < 0)
		width = -width;
	if (width == 1)
		width = 0;
	return (width);
}

int		ft_find_precision(char *spcf)
{
	int precision;

	while (*spcf != '.' && *spcf != '\0')
		spcf++;
	if (*spcf == '\0')
		return (-1);
	spcf++;
	if (*spcf != '\0' && *spcf == '-')
		spcf++;
	precision = ft_atoi(spcf);
	if (precision == 0)
		return (-1);
	return (precision);
}

t_spcf	ft_find_flags(t_spcf spcf)
{
	int i;

	spcf.minus = 0;
	if (ft_memchr(spcf.spcf, '-', spcf.size))
		spcf.minus = 1;
	spcf.plus = 0;
	if (ft_memchr(spcf.spcf, '+', spcf.size))
		spcf.plus = 1;
	spcf.sharp = 0;
	if (ft_memchr(spcf.spcf, '#', spcf.size)
		&& ft_memchr("Xxo", spcf.conversion, 3))
		spcf.sharp = 1;
	spcf.space = 0;
	if (ft_memchr(spcf.spcf, ' ', spcf.size))
		spcf.space = 1;
	spcf.zero = 0;
	i = 0;
	while ((spcf.spcf[i] < '1' || spcf.spcf[i] > '9') && spcf.spcf[i] != '\0')
	{
		if (spcf.spcf[i] == '0')
			spcf.zero = 1;
		i++;
	}
	return (spcf);
}

t_spcf	ft_find_all_flags(const char *format, int i)
{
	t_spcf spcf;

	spcf.spcf = ft_cut_specifier(format, i);
	spcf.size = ft_strlen(spcf.spcf);
	spcf.conversion = ft_find_conversion(spcf.spcf);
	spcf = ft_find_modifier(spcf);
	spcf.precision = ft_find_precision(spcf.spcf);
	spcf = ft_find_flags(spcf);
	spcf.width = ft_find_width(spcf);
	if (spcf.precision != -1 && spcf.sharp && spcf.conversion == 'o')
		spcf.precision -= 1;
	if (spcf.conversion == 'c' && MB_CUR_MAX != 4)
		spcf.modifier = 0;
	return (spcf);
}
