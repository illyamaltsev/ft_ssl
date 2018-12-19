/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:02:55 by imaltsev          #+#    #+#             */
/*   Updated: 2017/12/29 13:02:57 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_text(const char *format, int i)
{
	int count;

	count = 0;
	while (format[i] != '%' && format[i] != '\0')
	{
		ft_putchar(format[i]);
		i++;
		count++;
	}
	return (count);
}

int		ft_putzerochr(char *str, t_spcf spcf)
{
	if (spcf.width >= 2)
	{
		str++;
		ft_putnstr(str, spcf.width);
		return (spcf.width);
	}
	else
	{
		ft_putnstr(str, spcf.width + 1);
		return (spcf.width + 1);
	}
}

int		ft_print_format(va_list ap, const char *format, int i)
{
	char	*str;
	t_spcf	spcf;
	size_t	size;

	spcf = ft_find_all_flags(format, i);
	if (spcf.conversion == 's')
		str = ft_corect(ft_str(ap, &spcf), spcf, 0);
	else if (ft_memchr("di", spcf.conversion, 2))
		str = ft_corect(ft_int(ap, spcf), spcf, 0);
	else if (ft_memchr("ouxX", spcf.conversion, 4))
		str = ft_corect(ft_base(ap, spcf), spcf, 0);
	else if (spcf.conversion == 'c')
		str = ft_corect(ft_char(ap, &spcf), spcf, 0);
	else if (ft_memchr("p%", spcf.conversion, 2))
		str = ft_corect(ft_percent_pointer(&spcf, ap), spcf, 0);
	else
		str = ft_corect(ft_strdup(&spcf.conversion), spcf, 0);
	size = ft_strlen(str);
	if (spcf.conversion == 'C')
		size = ft_putzerochr(str, spcf);
	else
		ft_putnstr(str, size);
	free(str);
	free(spcf.spcf);
	return (size);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	int		k;
	va_list ap;

	i = 0;
	k = 0;
	if (format[0] != '\0' && format[0] == '%' && format[1] == '\0')
		return (0);
	va_start(ap, format);
	while (format[k] != '\0')
	{
		i += ft_print_text(format, k);
		k = ft_count_print_chars(format, k);
		if (format[k] != '\0')
		{
			i += ft_print_format(ap, format, k + 1);
			k += ft_count_format_chars(format, k + 1);
		}
	}
	va_end(ap);
	return (i);
}
