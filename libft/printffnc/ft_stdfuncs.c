/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdfuncs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:20:31 by imaltsev          #+#    #+#             */
/*   Updated: 2018/01/15 19:20:32 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_count_print_chars(const char *format, int i)
{
	while (format[i] != '%' && format[i] != '\0')
		i++;
	return (i);
}

int		ft_count_format_chars(const char *format, int i)
{
	int count;

	count = 2;
	while (ft_memchr(" 1234567890+-#.hlzj", format[i], 19))
	{
		count++;
		i++;
	}
	return (count);
}

int		ft_count_formats(const char *format)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] != '%' && format[i + 1] != '\0')
				count++;
			if (format[i + 1] == '%')
				count--;
		}
		i++;
	}
	return (count);
}

char	*ft_cut_specifier(const char *format, int i)
{
	char	*new_str;
	int		j;

	j = 0;
	new_str = ft_strnew(ft_count_format_chars(format, i));
	while (ft_memchr(" 1234567890+-#.hlzj", format[i], 19))
		new_str[j++] = format[i++];
	new_str[j] = format[i];
	return (new_str);
}

char	ft_find_conversion(char *spcf)
{
	int i;

	i = 0;
	while (ft_memchr(" 1234567890+-#.hlzj", spcf[i], 19))
		i++;
	return (spcf[i]);
}
