/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:03:01 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 20:04:37 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

u_int32_t		g_k[64] = {
	0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
	0x3956C25B, 0x59F111F1, 0x923F82A4, 0xAB1C5ED5,
	0xD807AA98, 0x12835B01, 0x243185BE, 0x550C7DC3,
	0x72BE5D74, 0x80DEB1FE, 0x9BDC06A7, 0xC19BF174,
	0xE49B69C1, 0xEFBE4786, 0x0FC19DC6, 0x240CA1CC,
	0x2DE92C6F, 0x4A7484AA, 0x5CB0A9DC, 0x76F988DA,
	0x983E5152, 0xA831C66D, 0xB00327C8, 0xBF597FC7,
	0xC6E00BF3, 0xD5A79147, 0x06CA6351, 0x14292967,
	0x27B70A85, 0x2E1B2138, 0x4D2C6DFC, 0x53380D13,
	0x650A7354, 0x766A0ABB, 0x81C2C92E, 0x92722C85,
	0xA2BFE8A1, 0xA81A664B, 0xC24B8B70, 0xC76C51A3,
	0xD192E819, 0xD6990624, 0xF40E3585, 0x106AA070,
	0x19A4C116, 0x1E376C08, 0x2748774C, 0x34B0BCB5,
	0x391C0CB3, 0x4ED8AA4A, 0x5B9CCA4F, 0x682E6FF3,
	0x748F82EE, 0x78A5636F, 0x84C87814, 0x8CC70208,
	0x90BEFFFA, 0xA4506CEB, 0xBEF9A3F7, 0xC67178F2
};

void		add_byte(t_string *w, u_int8_t byte)
{
	w->str = ft_realloc_free(w->str, w->size + 1);
	w->str[w->size] = byte;
	++(w->size);
}

void		init_w(t_string *w, char *str_input)
{
	size_t start_size;

	start_size = ft_strlen(str_input);
	w->str = ft_strdup(str_input);
	w->size = start_size;
	add_byte(w, 0x80);
	++(w->size);
	while (((w->size * 8) % 512) != 448)
		add_byte(w, 0x00);
	w->str = ft_realloc_free(w->str, w->size + 8);
	*(uint64_t *)&(w->str[w->size]) = swap_8_bytes((start_size * 8));
	w->size += 8;
}

void		init_sha256(t_string *w, char *str_input)
{
	init_w(w, str_input);
	g_a = 0x6A09E667;
	g_b = 0xBB67AE85;
	g_c = 0x3C6EF372;
	g_d = 0xA54FF53A;
	g_e = 0x510E527F;
	g_f = 0x9B05688C;
	g_g = 0x1F83D9AB;
	g_h = 0x5BE0CD19;
}
