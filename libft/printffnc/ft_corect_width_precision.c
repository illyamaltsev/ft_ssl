/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corect_width_precision.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 19:22:30 by imaltsev          #+#    #+#             */
/*   Updated: 2018/02/05 19:22:31 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_size(wchar_t *ws, int n, int i)
{
	int		j;
	int		f;
	int		ret;

	j = 0;
	f = 0;
	ret = 0;
	if (n < 1)
		return (n);
	while (ws != NULL && ws[j])
	{
		i = ft_bitsize(ws[j]);
		if (i <= 7)
			f = 1;
		else if (i <= 11)
			f = 2;
		else if (i <= 16)
			f = 3;
		else if (i > 16)
			f = 4;
		if ((ret + f) > n)
			return (ret);
		ret += f;
	}
	return (n);
}

char	*ft_corect_precision_idouxp(char *str, char c, int size, t_spcf spcf)
{
	char *str_c;
	char *new;
	char *tmp;
	char *tmp2;

	tmp = NULL;
	tmp2 = str;
	new = ft_strnew(spcf.precision + 0);
	str_c = ft_strnew(2);
	str_c[0] = c;
	new = ft_memset(new, '0', spcf.precision - size);
	if (ft_memchr("+- ", c, 3))
	{
		tmp = ft_strjoin(str_c, new);
		tmp2++;
	}
	if (!tmp)
		tmp = new;
	else
		free(new);
	new = ft_strjoin(tmp, tmp2);
	free(str);
	free(tmp);
	free(str_c);
	return (new);
}

char	*ft_corect_precision(char *str, t_spcf spcf)
{
	char	*new;
	int		str_size;

	new = NULL;
	str_size = ft_strlen(str);
	if (str_size > spcf.precision && !ft_memchr("idouxXp", spcf.conversion, 7))
	{
		new = ft_strnew(spcf.precision);
		new = ft_strncpy(new, str, spcf.precision);
		free(str);
	}
	else if (ft_memchr("idouxXp", spcf.conversion, 7))
	{
		if (ft_memchr("+- ", str[0], 3))
			str_size--;
		if (str_size < spcf.precision)
			new = ft_corect_precision_idouxp(str, str[0], str_size, spcf);
	}
	if (!new)
		new = str;
	return (new);
}

char	*ft_corect_width(char *str, t_spcf spcf, int i)
{
	char	*tmp;
	char	*tmp2;
	char	*new;

	new = ft_memset(ft_strnew(spcf.width), ' ', spcf.width);
	if (spcf.zero && !(spcf.minus) && spcf.precision == -1
	&& (!ft_memchr(spcf.spcf, '.', spcf.size)
	|| !ft_memchr("idouxXp", spcf.conversion, 7)))
		new = ft_memset(new, '0', spcf.width);
	while (spcf.minus && str[++i] != '\0')
		new[i] = str[i];
	if (!spcf.minus && (tmp = new + ft_strlen(str)))
	{
		if ((tmp2 = str) && ft_memchr(" +-", str[0], 3) && tmp[0] == '0')
		{
			tmp = new + ft_strlen(str) - 1;
			tmp[0] = tmp2[0];
			tmp2++;
		}
		tmp = ft_strjoin(tmp, tmp2);
		free(new);
		new = tmp;
	}
	free(str);
	return (new);
}
