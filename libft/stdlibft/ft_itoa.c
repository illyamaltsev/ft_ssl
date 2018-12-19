/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:13:49 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/08 17:13:51 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			count_future_len(intmax_t n)
{
	int len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static intmax_t		f_10(int n)
{
	intmax_t res;

	res = 1;
	while (n > 0)
	{
		res = res * 10;
		n--;
	}
	return (res);
}

char				*ft_itoa(intmax_t n)
{
	char	*fresh;
	int		len;
	int		i;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	i = 0;
	len = count_future_len(n);
	fresh = ft_strnew(len);
	if (n < 0 && len--)
	{
		fresh[i] = '-';
		i++;
		n = -1 * n;
	}
	while (len > 0)
	{
		fresh[i] = (n / f_10(len - 1)) + 48;
		n = n - ((n / f_10(len - 1)) * f_10(len - 1));
		len--;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
