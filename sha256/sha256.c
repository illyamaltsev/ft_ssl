//
// Created by Illya MALTSEV on 6/9/18.
//

#include "sha256.h"

#define E0 (av[0])
#define E1 (av[1])
#define MA (av[2])
#define CH (av[3])
#define T1 (av[4])
#define T2 (av[5])

static void     calculate()
{
	uint32_t	av[6];
	int			i;

	i = 0;
	while (i < 64)
	{
		E0 = rotr(g_A, 2) ^ rotr(g_A, 13) ^ rotr(g_A, 22);
		MA = (g_A & g_B) ^ (g_A & g_C) ^ (g_B & g_C);
		T2 = E0 + MA;
		E1 = rotr(g_E, 6) ^ rotr(g_E, 11) ^ rotr(g_E, 25);
		CH = (g_E & g_F) ^ (~(g_E) & g_G);
		T1 = g_H + E1 + CH + g_K[i] + g_W[i];
		g_H = g_G;
		g_G = g_F;
		g_F = g_E;
		g_E = g_D + T1;
		g_D = g_C;
		g_C = g_B;
		g_B = g_A;
		g_A = T1 + T2;
		i++;
	}
}

void	algorithm(t_string *W, size_t delta)
{
	uint32_t h[8];

	prepare_g_W(W);
	while(delta < W->size / 4)
	{
		h[0] = g_A;
		h[1] = g_B;
		h[2] = g_C;
		h[3] = g_D;
		h[4] = g_E;
		h[5] = g_F;
		h[6] = g_G;
		h[7] = g_H;
		calculate();
		g_A += h[0];
		g_B += h[1];
		g_C += h[2];
		g_D += h[3];
		g_E += h[4];
		g_F += h[5];
		g_G += h[6];
		g_H += h[7];
		delta += 16;
	}
}

void		sha25_clear_memory(t_string ** W)
{
	free((*W)->str);
	free(*W);
}

uint8_t		*sha256(char *str_input)
{
	t_string	*W;
	uint8_t		*ret;

	W = (t_string *)ft_memalloc(sizeof(t_string));
	init_sha256(W, str_input);
	algorithm(W, 0);
	ret = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (32 + 1));
	((uint32_t *)ret)[0] = reverse_4_bytes(g_A);
	((uint32_t *)ret)[1] = reverse_4_bytes(g_B);
	((uint32_t *)ret)[2] = reverse_4_bytes(g_C);
	((uint32_t *)ret)[3] = reverse_4_bytes(g_D);
	((uint32_t *)ret)[4] = reverse_4_bytes(g_E);
	((uint32_t *)ret)[5] = reverse_4_bytes(g_F);
	((uint32_t *)ret)[6] = reverse_4_bytes(g_G);
	((uint32_t *)ret)[7] = reverse_4_bytes(g_H);
	ret[32] = '\0';
	sha25_clear_memory(&W);
	return (ret);
}