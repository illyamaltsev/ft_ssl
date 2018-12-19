/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_openers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 15:57:38 by imaltsev          #+#    #+#             */
/*   Updated: 2018/02/05 15:57:39 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str(va_list ap, t_spcf *spcf)
{
	wchar_t *wct;
	char	*str;
	char	*tmp;

	if (spcf->modifier == 'l')
	{
		wct = va_arg(ap, wchar_t *);
		if (spcf->precision == -1 && ft_memchr(spcf->spcf, '.', spcf->size))
			return (ft_strnew(0));
		if (!wct)
			return (ft_strdup("(null)"));
		spcf->precision = ft_size(wct, spcf->precision, 0);
		str = ft_wstrtoa(wct);
	}
	else
	{
		str = va_arg(ap, char *);
		if (spcf->precision == -1 && ft_memchr(spcf->spcf, '.', spcf->size))
			return (ft_strnew(0));
		if (!str)
			return (ft_strdup("(null)"));
		tmp = str;
		str = ft_strcpy(ft_strnew(ft_strlen(str)), tmp);
	}
	return (str);
}

char	*ft_int(va_list ap, t_spcf spcf)
{
	size_t	num;
	char	*str;

	num = va_arg(ap, size_t);
	if (num == 0 && spcf.precision == -1
		&& ft_memchr(spcf.spcf, '.', spcf.size))
		return (ft_strnew(0));
	if (spcf.modifier == 'z')
		num = (size_t)num;
	else if (spcf.modifier == 'j')
		num = (intmax_t)num;
	else if (spcf.modifier == 'L')
		num = (long long int)num;
	else if (spcf.modifier == 'l')
		num = (long int)num;
	else if (spcf.modifier == 'h')
		num = (short int)num;
	else if (spcf.modifier == 'H')
		num = (signed char)num;
	else
		num = (int)num;
	str = ft_itoa(num);
	return (str);
}

char	*ft_base(va_list ap, t_spcf spcf)
{
	uintmax_t	num;
	char		*str;

	num = va_arg(ap, uintmax_t);
	if (num == 0 && ft_memchr(spcf.spcf, '.', spcf.size))
		return (ft_strnew(0));
	if (spcf.modifier == 'z')
		num = (size_t)num;
	else if (spcf.modifier == 'L')
		num = (unsigned long long)num;
	else if (spcf.modifier == 'l')
		num = (unsigned long)num;
	else if (spcf.modifier == 'h')
		num = (unsigned short)num;
	else if (spcf.modifier == 'H')
		num = (unsigned char)num;
	else if (spcf.modifier != 'j')
		num = (unsigned int)num;
	if (spcf.conversion == 'x' || spcf.conversion == 'X')
		str = ft_itoa_base(num, 16);
	else if (spcf.conversion == 'u')
		str = ft_itoa_base(num, 10);
	else
		str = ft_itoa_base(num, 8);
	return (str);
}

char	*ft_char(va_list ap, t_spcf *spcf)
{
	char	*str;
	wchar_t	wc;

	if (spcf->modifier == 'l')
	{
		wc = va_arg(ap, wint_t);
		str = ft_strnew(4);
		ft_wchtoa(wc, str, 0);
	}
	else
	{
		str = ft_strnew(1);
		str[0] = va_arg(ap, int);
	}
	if (str[0] == '\0')
		spcf->conversion = 'C';
	return (str);
}

char	*ft_percent_pointer(t_spcf *spcf, va_list ap)
{
	intmax_t	num;
	char		*str;

	if (spcf->conversion == '%')
	{
		str = ft_strnew(1);
		str[0] = '%';
	}
	else
	{
		num = va_arg(ap, uintmax_t);
		spcf->sharp = 1;
		if (num == 0 && spcf->precision == -1
			&& ft_memchr(spcf->spcf, '.', spcf->size))
			return (ft_strnew(0));
		if (num == 0 && spcf->zero && spcf->width >= 2)
			spcf->width -= 2;
		str = ft_itoa_base(num, 16);
	}
	return (str);
}
