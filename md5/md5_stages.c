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

void	stage_1(t_md5 *m, int d)
{
	uint32_t	*t;
	uint32_t	*x;

	t = m->t;
	x = m->x;
	m->a = m->b + b_r((m->a + f(m->b, m->c, m->d) + x[0 + d] + t[1]), 7);
	m->d = m->a + b_r((m->d + f(m->a, m->b, m->c) + x[1 + d] + t[2]), 12);
	m->c = m->d + b_r((m->c + f(m->d, m->a, m->b) + x[2 + d] + t[3]), 17);
	m->b = m->c + b_r((m->b + f(m->c, m->d, m->a) + x[3 + d] + t[4]), 22);
	m->a = m->b + b_r((m->a + f(m->b, m->c, m->d) + x[4 + d] + t[5]), 7);
	m->d = m->a + b_r((m->d + f(m->a, m->b, m->c) + x[5 + d] + t[6]), 12);
	m->c = m->d + b_r((m->c + f(m->d, m->a, m->b) + x[6 + d] + t[7]), 17);
	m->b = m->c + b_r((m->b + f(m->c, m->d, m->a) + x[7 + d] + t[8]), 22);
	m->a = m->b + b_r((m->a + f(m->b, m->c, m->d) + x[8 + d] + t[9]), 7);
	m->d = m->a + b_r((m->d + f(m->a, m->b, m->c) + x[9 + d] + t[10]), 12);
	m->c = m->d + b_r((m->c + f(m->d, m->a, m->b) + x[10 + d] + t[11]), 17);
	m->b = m->c + b_r((m->b + f(m->c, m->d, m->a) + x[11 + d] + t[12]), 22);
	m->a = m->b + b_r((m->a + f(m->b, m->c, m->d) + x[12 + d] + t[13]), 7);
	m->d = m->a + b_r((m->d + f(m->a, m->b, m->c) + x[13 + d] + t[14]), 12);
	m->c = m->d + b_r((m->c + f(m->d, m->a, m->b) + x[14 + d] + t[15]), 17);
	m->b = m->c + b_r((m->b + f(m->c, m->d, m->a) + x[15 + d] + t[16]), 22);
}

void	stage_2(t_md5 *m, int d)
{
	uint32_t	*t;
	uint32_t	*x;

	t = m->t;
	x = m->x;
	m->a = m->b + b_r((m->a + g(m->b, m->c, m->d) + x[1 + d] + t[17]), 5);
	m->d = m->a + b_r((m->d + g(m->a, m->b, m->c) + x[6 + d] + t[18]), 9);
	m->c = m->d + b_r((m->c + g(m->d, m->a, m->b) + x[11 + d] + t[19]), 14);
	m->b = m->c + b_r((m->b + g(m->c, m->d, m->a) + x[0 + d] + t[20]), 20);
	m->a = m->b + b_r((m->a + g(m->b, m->c, m->d) + x[5 + d] + t[21]), 5);
	m->d = m->a + b_r((m->d + g(m->a, m->b, m->c) + x[10 + d] + t[22]), 9);
	m->c = m->d + b_r((m->c + g(m->d, m->a, m->b) + x[15 + d] + t[23]), 14);
	m->b = m->c + b_r((m->b + g(m->c, m->d, m->a) + x[4 + d] + t[24]), 20);
	m->a = m->b + b_r((m->a + g(m->b, m->c, m->d) + x[9 + d] + t[25]), 5);
	m->d = m->a + b_r((m->d + g(m->a, m->b, m->c) + x[14 + d] + t[26]), 9);
	m->c = m->d + b_r((m->c + g(m->d, m->a, m->b) + x[3 + d] + t[27]), 14);
	m->b = m->c + b_r((m->b + g(m->c, m->d, m->a) + x[8 + d] + t[28]), 20);
	m->a = m->b + b_r((m->a + g(m->b, m->c, m->d) + x[13 + d] + t[29]), 5);
	m->d = m->a + b_r((m->d + g(m->a, m->b, m->c) + x[2 + d] + t[30]), 9);
	m->c = m->d + b_r((m->c + g(m->d, m->a, m->b) + x[7 + d] + t[31]), 14);
	m->b = m->c + b_r((m->b + g(m->c, m->d, m->a) + x[12 + d] + t[32]), 20);
}

void	stage_3(t_md5 *m, int d)
{
	uint32_t	*t;
	uint32_t	*x;

	t = m->t;
	x = m->x;
	m->a = m->b + b_r((m->a + h(m->b, m->c, m->d) + x[5 + d] + t[33]), 4);
	m->d = m->a + b_r((m->d + h(m->a, m->b, m->c) + x[8 + d] + t[34]), 11);
	m->c = m->d + b_r((m->c + h(m->d, m->a, m->b) + x[11 + d] + t[35]), 16);
	m->b = m->c + b_r((m->b + h(m->c, m->d, m->a) + x[14 + d] + t[36]), 23);
	m->a = m->b + b_r((m->a + h(m->b, m->c, m->d) + x[1 + d] + t[37]), 4);
	m->d = m->a + b_r((m->d + h(m->a, m->b, m->c) + x[4 + d] + t[38]), 11);
	m->c = m->d + b_r((m->c + h(m->d, m->a, m->b) + x[7 + d] + t[39]), 16);
	m->b = m->c + b_r((m->b + h(m->c, m->d, m->a) + x[10 + d] + t[40]), 23);
	m->a = m->b + b_r((m->a + h(m->b, m->c, m->d) + x[13 + d] + t[41]), 4);
	m->d = m->a + b_r((m->d + h(m->a, m->b, m->c) + x[0 + d] + t[42]), 11);
	m->c = m->d + b_r((m->c + h(m->d, m->a, m->b) + x[3 + d] + t[43]), 16);
	m->b = m->c + b_r((m->b + h(m->c, m->d, m->a) + x[6 + d] + t[44]), 23);
	m->a = m->b + b_r((m->a + h(m->b, m->c, m->d) + x[9 + d] + t[45]), 4);
	m->d = m->a + b_r((m->d + h(m->a, m->b, m->c) + x[12 + d] + t[46]), 11);
	m->c = m->d + b_r((m->c + h(m->d, m->a, m->b) + x[15 + d] + t[47]), 16);
	m->b = m->c + b_r((m->b + h(m->c, m->d, m->a) + x[2 + d] + t[48]), 23);
}

void	stage_4(t_md5 *m, int d)
{
	uint32_t	*t;
	uint32_t	*x;

	t = m->t;
	x = m->x;
	m->a = m->b + b_r((m->a + i(m->b, m->c, m->d) + x[0 + d] + t[49]), 6);
	m->d = m->a + b_r((m->d + i(m->a, m->b, m->c) + x[7 + d] + t[50]), 10);
	m->c = m->d + b_r((m->c + i(m->d, m->a, m->b) + x[14 + d] + t[51]), 15);
	m->b = m->c + b_r((m->b + i(m->c, m->d, m->a) + x[5 + d] + t[52]), 21);
	m->a = m->b + b_r((m->a + i(m->b, m->c, m->d) + x[12 + d] + t[53]), 6);
	m->d = m->a + b_r((m->d + i(m->a, m->b, m->c) + x[3 + d] + t[54]), 10);
	m->c = m->d + b_r((m->c + i(m->d, m->a, m->b) + x[10 + d] + t[55]), 15);
	m->b = m->c + b_r((m->b + i(m->c, m->d, m->a) + x[1 + d] + t[56]), 21);
	m->a = m->b + b_r((m->a + i(m->b, m->c, m->d) + x[8 + d] + t[57]), 6);
	m->d = m->a + b_r((m->d + i(m->a, m->b, m->c) + x[15 + d] + t[58]), 10);
	m->c = m->d + b_r((m->c + i(m->d, m->a, m->b) + x[6 + d] + t[59]), 15);
	m->b = m->c + b_r((m->b + i(m->c, m->d, m->a) + x[13 + d] + t[60]), 21);
	m->a = m->b + b_r((m->a + i(m->b, m->c, m->d) + x[4 + d] + t[61]), 6);
	m->d = m->a + b_r((m->d + i(m->a, m->b, m->c) + x[11 + d] + t[62]), 10);
	m->c = m->d + b_r((m->c + i(m->d, m->a, m->b) + x[2 + d] + t[63]), 15);
	m->b = m->c + b_r((m->b + i(m->c, m->d, m->a) + x[9 + d] + t[64]), 21);
}

void	stages(t_md5 *m)
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	size_t		delta;

	delta = 0;
	while (delta < m->size / 4)
	{
		a = m->a;
		b = m->b;
		c = m->c;
		d = m->d;
		stage_1(m, delta);
		stage_2(m, delta);
		stage_3(m, delta);
		stage_4(m, delta);
		m->a += a;
		m->b += b;
		m->c += c;
		m->d += d;
		delta += 16;
	}
}
