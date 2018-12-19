/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_t_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:28:21 by imaltsev          #+#    #+#             */
/*   Updated: 2018/01/17 19:28:22 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_bitsize(unsigned int ch)
{
	int i;

	i = 0;
	while (ch != 0)
	{
		ch = ch >> 1;
		i++;
	}
	return (i);
}

void	ft_wct4bits(wchar_t ch, char *str, int i)
{
	unsigned char mask1;
	unsigned char mask2;

	mask1 = 240;
	mask2 = 128;
	str[i] = (ch >> 18) | mask1;
	str[i + 1] = ((ch >> 12) & 63) | mask2;
	str[i + 2] = ((ch >> 6) & 63) | mask2;
	str[i + 3] = (ch & 63) | mask2;
}

void	ft_wct3bits(wchar_t ch, char *str, int i)
{
	unsigned char mask1;
	unsigned char mask2;

	mask1 = 224;
	mask2 = 128;
	str[i] = (ch >> 12) | mask1;
	str[i + 1] = ((ch >> 6) & 63) | mask2;
	str[i + 2] = (ch & 63) | mask2;
}

void	ft_wct2bits(wchar_t ch, char *str, int i)
{
	unsigned char mask1;
	unsigned char mask2;

	mask1 = 192;
	mask2 = 128;
	str[i] = (ch >> 6) | mask1;
	str[i + 1] = (ch & 63) | mask2;
}

int		ft_wchtoa(wchar_t ch, char *str, int i)
{
	int		size;

	size = ft_bitsize(ch);
	if (size <= 7)
	{
		str[i] = (char)ch;
		return (1);
	}
	else if (size <= 11)
	{
		ft_wct2bits(ch, str, i);
		return (2);
	}
	else if (size <= 16)
	{
		ft_wct3bits(ch, str, i);
		return (3);
	}
	else
	{
		ft_wct4bits(ch, str, i);
		return (4);
	}
}
