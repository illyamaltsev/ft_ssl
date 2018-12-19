/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:40:05 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:40:08 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"
#include "md5.h"

void	md5_add_byte(t_abcdTX *m, u_int8_t byte)
{
	m->str = ft_realloc_free(m->str, m->size + 1);
	m->str[m->size] = byte;
	++(m->size);
}

void	init_abcd(t_abcdTX *abcd)
{
	abcd->A = 0x67452301;
	abcd->B = 0xefcdab89;
	abcd->C = 0x98badcfe;
	abcd->D = 0x10325476;
}

void	init_X(t_abcdTX *m, char *str_input)
{
	size_t start_size;

	start_size = ft_strlen(str_input);
	m->str = ft_strdup(str_input);
	m->size = start_size;
	md5_add_byte(m, 0x80);
	++(m->size);
	while (((m->size * 8) % 512) != 448)
		md5_add_byte(m, 0x00);
	m->str = ft_realloc_free(m->str, m->size + 8);
	*(uint64_t *)&(m->str[m->size]) = start_size * 8;
	m->X = (uint32_t *)m->str;
	m->size += 2;
}

void	init_T(t_abcdTX *m)
{
	int i;

	i = 0;
	while (i < 65)
	{
		m->T[i] = (uint32_t)(0x100000000 * fabs(sin(i)));
		i++;
	}
}

void	init_md5(t_abcdTX *m, char *str_input)
{
	init_abcd(m);
	init_X(m, str_input);
	init_T(m);
}
