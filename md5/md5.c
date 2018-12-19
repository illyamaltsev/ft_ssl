/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:32:21 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:32:22 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

void		md5_clear_memory(t_abcdTX **m)
{
	free((*m)->X);
	free(*m);
}

uint8_t		*ft_md5(char *str_input)
{
	t_abcdTX	*m;
	uint8_t		*ret;

	m = (t_abcdTX*)ft_memalloc(sizeof(t_abcdTX));
	init_md5(m, str_input);
	stages(m);
	ret = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (16 + 1));
	((uint32_t *)ret)[0] = m->A;
	((uint32_t *)ret)[1] = m->B;
	((uint32_t *)ret)[2] = m->C;
	((uint32_t *)ret)[3] = m->D;
	ret[16] = '\0';
	md5_clear_memory(&m);
	return (ret);
}
