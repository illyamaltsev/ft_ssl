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

void		md5_clear_memory(t_md5 **m)
{
	free((*m)->x);
	free(*m);
}

uint8_t		*ft_md5(char *str_input)
{
	t_md5		*m;
	uint8_t		*ret;

	m = (t_md5*)ft_memalloc(sizeof(t_md5));
	init_md5(m, str_input);
	stages(m);
	ret = (uint8_t *)ft_memalloc(sizeof(uint8_t) * (16 + 1));
	((uint32_t *)ret)[0] = m->a;
	((uint32_t *)ret)[1] = m->b;
	((uint32_t *)ret)[2] = m->c;
	((uint32_t *)ret)[3] = m->d;
	ret[16] = '\0';
	md5_clear_memory(&m);
	return (ret);
}
