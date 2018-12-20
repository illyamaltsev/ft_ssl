/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:59:22 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:59:23 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

#define E0 (av[0])
#define E1 (av[1])
#define MA (av[2])
#define CH (av[3])
#define T1 (av[4])
#define T2 (av[5])

void	calculate(void)
{
	uint32_t	av[6];
	int			i;

	i = 0;
	while (i < 64)
	{
		E0 = rotr(g_a, 2) ^ rotr(g_a, 13) ^ rotr(g_a, 22);
		MA = (g_a & g_b) ^ (g_a & g_c) ^ (g_b & g_c);
		T2 = E0 + MA;
		E1 = rotr(g_e, 6) ^ rotr(g_e, 11) ^ rotr(g_e, 25);
		CH = (g_e & g_f) ^ (~(g_e) & g_g);
		T1 = g_h + E1 + CH + g_k[i] + g_w[i];
		g_h = g_g;
		g_g = g_f;
		g_f = g_e;
		g_e = g_d + T1;
		g_d = g_c;
		g_c = g_b;
		g_b = g_a;
		g_a = T1 + T2;
		i++;
	}
}

void	algorithm(t_string *w, size_t delta)
{
	uint32_t h[8];

	while (prepare_g_w(w))
	{
		h[0] = g_a;
		h[1] = g_b;
		h[2] = g_c;
		h[3] = g_d;
		h[4] = g_e;
		h[5] = g_f;
		h[6] = g_g;
		h[7] = g_h;
		calculate();
		g_a += h[0];
		g_b += h[1];
		g_c += h[2];
		g_d += h[3];
		g_e += h[4];
		g_f += h[5];
		g_g += h[6];
		g_h += h[7];
		delta += 16;
	}
}

void	sha256_clear_memory(t_string **w)
{
	free((*w)->tofree);
	free(*w);
}

uint8_t	*sha256(char *str_input)
{
	t_string	*w;
	uint8_t		*ret;

	w = (t_string *)ft_memalloc(sizeof(t_string));
	init_sha256(w, str_input);
	algorithm(w, 0);
	ret = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (32 + 1));
	((uint32_t *)ret)[0] = reverse_4_bytes(g_a);
	((uint32_t *)ret)[1] = reverse_4_bytes(g_b);
	((uint32_t *)ret)[2] = reverse_4_bytes(g_c);
	((uint32_t *)ret)[3] = reverse_4_bytes(g_d);
	((uint32_t *)ret)[4] = reverse_4_bytes(g_e);
	((uint32_t *)ret)[5] = reverse_4_bytes(g_f);
	((uint32_t *)ret)[6] = reverse_4_bytes(g_g);
	((uint32_t *)ret)[7] = reverse_4_bytes(g_h);
	ret[32] = '\0';
	sha256_clear_memory(&w);
	return (ret);
}
