/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_prepare_g_W.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:06:10 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 20:06:11 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

/*
**	s0 := (w[i-15] rotr 7) xor (w[i-15] rotr 18) xor (w[i-15] shr 3)
**	s1 := (w[i-2] rotr 17) xor (w[i-2] rotr 19) xor (w[i-2] shr 10)
**	w[i] := w[i-16] + s0 + w[i-7] + s1
*/

void	prepare_g_w(t_string *w)
{
	size_t	i;
	int		s0;
	int		s1;

	i = 0;
	ft_bzero(g_w, 64);
	while (i < w->size / 4)
	{
		g_w[i] = reverse_4_bytes(((uint32_t *)w->str)[i]);
		i++;
	}
	while (i < 64)
	{
		s0 = (rotr(g_w[i - 15], 7))
				^ (rotr(g_w[i - 15], 18)) ^ (g_w[i - 15] >> 3);
		s1 = (rotr(g_w[i - 2], 17))
				^ (rotr(g_w[i - 2], 19)) ^ (g_w[i - 2] >> 10);
		g_w[i] = g_w[i - 16] + s0 + g_w[i - 7] + s1;
		i++;
	}
}
