//
// Created by Illya MALTSEV on 6/11/18.
//

#include "sha256.h"

///s0 := (w[i-15] rotr 7) xor (w[i-15] rotr 18) xor (w[i-15] shr 3)
///s1 := (w[i-2] rotr 17) xor (w[i-2] rotr 19) xor (w[i-2] shr 10)
///w[i] := w[i-16] + s0 + w[i-7] + s1

void	prepare_g_W(t_string *W)
{
	size_t i;
	int s0;
	int s1;

	i = 0;
	ft_bzero(g_W, 64);
	while (i < W->size/4)
	{
		g_W[i] = reverse_4_bytes(((uint32_t *)W->str)[i]);
		i++;
	}
	while (i < 64)
	{
		s0 = (rotr(g_W[i - 15], 7)) ^ (rotr(g_W[i - 15], 18)) ^ (g_W[i - 15] >> 3);
		s1 = (rotr(g_W[i - 2], 17)) ^ (rotr(g_W[i - 2], 19)) ^ (g_W[i - 2] >> 10);
		g_W[i] = g_W[i - 16] + s0 + g_W[i - 7] + s1;
		i++;
	}
}
