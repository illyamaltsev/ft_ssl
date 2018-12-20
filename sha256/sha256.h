/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:02:31 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 20:02:34 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/mylibft.h"

uint32_t		g_a;
uint32_t		g_b;
uint32_t		g_c;
uint32_t		g_d;
uint32_t		g_e;
uint32_t		g_f;
uint32_t		g_g;
uint32_t		g_h;
uint32_t		g_w[64];
u_int32_t		g_k[64] = {0x428A2F98, 0x71374491, 0xB5C0FBCF, 0xE9B5DBA5,
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

typedef	struct	s_string
{
	char	*str;
	size_t	size;
}				t_string;

/*
**	sha256.c
*/
uint8_t			*sha256(char *str_input);

/*
**	init_sha256.c
*/
void			init_sha256(t_string *w, char *str_input);

/*
**	prepare_g_w.c
*/
void			prepare_g_w(t_string *w);

/*
**	tools_sha265.c
*/
uint32_t		reverse_4_bytes(uint32_t b);
uint64_t		swap_8_bytes(uint64_t b);
uint32_t		rotr(uint32_t b, uint32_t offset);

#endif
