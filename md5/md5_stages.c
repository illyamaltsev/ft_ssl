/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_stages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:48:54 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:48:55 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void	stage_1(t_abcdTX *m, int d)
{
	m->A = m->B + b_r((m->A + F(m->B, m->C, m->D) + m->X[0 + d] + m->T[1]), 7);
	m->D = m->A + b_r((m->D + F(m->A, m->B, m->C) + m->X[1 + d] + m->T[2]), 12);
	m->C = m->D + b_r((m->C + F(m->D, m->A, m->B) + m->X[2 + d] + m->T[3]), 17);
	m->B = m->C + b_r((m->B + F(m->C, m->D, m->A) + m->X[3 + d] + m->T[4]), 22);
	m->A = m->B + b_r((m->A + F(m->B, m->C, m->D) + m->X[4 + d] + m->T[5]), 7);
	m->D = m->A + b_r((m->D + F(m->A, m->B, m->C) + m->X[5 + d] + m->T[6]), 12);
	m->C = m->D + b_r((m->C + F(m->D, m->A, m->B) + m->X[6 + d] + m->T[7]), 17);
	m->B = m->C + b_r((m->B + F(m->C, m->D, m->A) + m->X[7 + d] + m->T[8]), 22);
	m->A = m->B + b_r((m->A + F(m->B, m->C, m->D) + m->X[8 + d] + m->T[9]), 7);
	m->D = m->A + b_r((m->D + F(m->A, m->B, m->C) + m->X[9 + d] + m->T[10]), 12);
	m->C = m->D + b_r((m->C + F(m->D, m->A, m->B) + m->X[10 + d] + m->T[11]), 17);
	m->B = m->C + b_r((m->B + F(m->C, m->D, m->A) + m->X[11 + d] + m->T[12]), 22);
	m->A = m->B + b_r((m->A + F(m->B, m->C, m->D) + m->X[12 + d] + m->T[13]), 7);
	m->D = m->A + b_r((m->D + F(m->A, m->B, m->C) + m->X[13 + d] + m->T[14]), 12);
	m->C = m->D + b_r((m->C + F(m->D, m->A, m->B) + m->X[14 + d] + m->T[15]), 17);
	m->B = m->C + b_r((m->B + F(m->C, m->D, m->A) + m->X[15 + d] + m->T[16]), 22);
}

void	stage_2(t_abcdTX *m, int d)
{
	m->A = m->B + b_r((m->A + G(m->B, m->C, m->D) + m->X[1 + d] + m->T[17]), 5);
	m->D = m->A + b_r((m->D + G(m->A, m->B, m->C) + m->X[6 + d] + m->T[18]), 9);
	m->C = m->D + b_r((m->C + G(m->D, m->A, m->B) + m->X[11 + d] + m->T[19]), 14);
	m->B = m->C + b_r((m->B + G(m->C, m->D, m->A) + m->X[0 + d] + m->T[20]), 20);
	m->A = m->B + b_r((m->A + G(m->B, m->C, m->D) + m->X[5 + d] + m->T[21]), 5);
	m->D = m->A + b_r((m->D + G(m->A, m->B, m->C) + m->X[10 + d] + m->T[22]), 9);
	m->C = m->D + b_r((m->C + G(m->D, m->A, m->B) + m->X[15 + d] + m->T[23]), 14);
	m->B = m->C + b_r((m->B + G(m->C, m->D, m->A) + m->X[4 + d] + m->T[24]), 20);
	m->A = m->B + b_r((m->A + G(m->B, m->C, m->D) + m->X[9 + d] + m->T[25]), 5);
	m->D = m->A + b_r((m->D + G(m->A, m->B, m->C) + m->X[14 + d] + m->T[26]), 9);
	m->C = m->D + b_r((m->C + G(m->D, m->A, m->B) + m->X[3 + d] + m->T[27]), 14);
	m->B = m->C + b_r((m->B + G(m->C, m->D, m->A) + m->X[8 + d] + m->T[28]), 20);
	m->A = m->B + b_r((m->A + G(m->B, m->C, m->D) + m->X[13 + d] + m->T[29]), 5);
	m->D = m->A + b_r((m->D + G(m->A, m->B, m->C) + m->X[2 + d] + m->T[30]), 9);
	m->C = m->D + b_r((m->C + G(m->D, m->A, m->B) + m->X[7 + d] + m->T[31]), 14);
	m->B = m->C + b_r((m->B + G(m->C, m->D, m->A) + m->X[12 + d] + m->T[32]), 20);
}

void	stage_3(t_abcdTX *m, int d)
{
	m->A = m->B + b_r((m->A + H(m->B, m->C, m->D) + m->X[5 + d] + m->T[33]), 4);
	m->D = m->A + b_r((m->D + H(m->A, m->B, m->C) + m->X[8 + d] + m->T[34]), 11);
	m->C = m->D + b_r((m->C + H(m->D, m->A, m->B) + m->X[11 + d] + m->T[35]), 16);
	m->B = m->C + b_r((m->B + H(m->C, m->D, m->A) + m->X[14 + d] + m->T[36]), 23);
	m->A = m->B + b_r((m->A + H(m->B, m->C, m->D) + m->X[1 + d] + m->T[37]), 4);
	m->D = m->A + b_r((m->D + H(m->A, m->B, m->C) + m->X[4 + d] + m->T[38]), 11);
	m->C = m->D + b_r((m->C + H(m->D, m->A, m->B) + m->X[7 + d] + m->T[39]), 16);
	m->B = m->C + b_r((m->B + H(m->C, m->D, m->A) + m->X[10 + d] + m->T[40]), 23);
	m->A = m->B + b_r((m->A + H(m->B, m->C, m->D) + m->X[13 + d] + m->T[41]), 4);
	m->D = m->A + b_r((m->D + H(m->A, m->B, m->C) + m->X[0 + d] + m->T[42]), 11);
	m->C = m->D + b_r((m->C + H(m->D, m->A, m->B) + m->X[3 + d] + m->T[43]), 16);
	m->B = m->C + b_r((m->B + H(m->C, m->D, m->A) + m->X[6 + d] + m->T[44]), 23);
	m->A = m->B + b_r((m->A + H(m->B, m->C, m->D) + m->X[9 + d] + m->T[45]), 4);
	m->D = m->A + b_r((m->D + H(m->A, m->B, m->C) + m->X[12 + d] + m->T[46]), 11);
	m->C = m->D + b_r((m->C + H(m->D, m->A, m->B) + m->X[15 + d] + m->T[47]), 16);
	m->B = m->C + b_r((m->B + H(m->C, m->D, m->A) + m->X[2 + d] + m->T[48]), 23);
}

void	stage_4(t_abcdTX *m, int d)
{
	m->A = m->B + b_r((m->A + I(m->B, m->C, m->D) + m->X[0 + d] + m->T[49]), 6);
	m->D = m->A + b_r((m->D + I(m->A, m->B, m->C) + m->X[7 + d] + m->T[50]), 10);
	m->C = m->D + b_r((m->C + I(m->D, m->A, m->B) + m->X[14 + d] + m->T[51]), 15);
	m->B = m->C + b_r((m->B + I(m->C, m->D, m->A) + m->X[5 + d] + m->T[52]), 21);
	m->A = m->B + b_r((m->A + I(m->B, m->C, m->D) + m->X[12 + d] + m->T[53]), 6);
	m->D = m->A + b_r((m->D + I(m->A, m->B, m->C) + m->X[3 + d] + m->T[54]), 10);
	m->C = m->D + b_r((m->C + I(m->D, m->A, m->B) + m->X[10 + d] + m->T[55]), 15);
	m->B = m->C + b_r((m->B + I(m->C, m->D, m->A) + m->X[1 + d] + m->T[56]), 21);
	m->A = m->B + b_r((m->A + I(m->B, m->C, m->D) + m->X[8 + d] + m->T[57]), 6);
	m->D = m->A + b_r((m->D + I(m->A, m->B, m->C) + m->X[15 + d] + m->T[58]), 10);
	m->C = m->D + b_r((m->C + I(m->D, m->A, m->B) + m->X[6 + d] + m->T[59]), 15);
	m->B = m->C + b_r((m->B + I(m->C, m->D, m->A) + m->X[13 + d] + m->T[60]), 21);
	m->A = m->B + b_r((m->A + I(m->B, m->C, m->D) + m->X[4 + d] + m->T[61]), 6);
	m->D = m->A + b_r((m->D + I(m->A, m->B, m->C) + m->X[11 + d] + m->T[62]), 10);
	m->C = m->D + b_r((m->C + I(m->D, m->A, m->B) + m->X[2 + d] + m->T[63]), 15);
	m->B = m->C + b_r((m->B + I(m->C, m->D, m->A) + m->X[9 + d] + m->T[64]), 21);
}

void	stages(t_abcdTX *m)
{
	uint32_t	A;
	uint32_t	B;
	uint32_t	C;
	uint32_t	D;
	size_t		delta;

	delta = 0;
	while (delta < m->size / 4)
	{
		A = m->A;
		B = m->B;
		C = m->C;
		D = m->D;
		stage_1(m, delta);
		stage_2(m, delta);
		stage_3(m, delta);
		stage_4(m, delta);
		m->A += A;
		m->B += B;
		m->C += C;
		m->D += D;
		delta += 16;
	}
}
