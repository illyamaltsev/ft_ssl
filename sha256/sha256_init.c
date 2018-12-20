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
