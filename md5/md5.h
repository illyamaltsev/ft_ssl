/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:32:21 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:32:22 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MD5_H
# define MD5_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/mylibft.h"

typedef struct	s_md5
{
	uint32_t	a;
	uint32_t	b;
	uint32_t	c;
	uint32_t	d;
	uint32_t	t[65];
	uint32_t	*x;
	char		*str;
	size_t		size;
}				t_md5;

/*
**	md5.c
*/
uint8_t			*ft_md5(char *str_input);

/*
**	init.c
*/
void			init_md5(t_md5 *m, char *str_input);
void			init_abcd(t_md5 *abcd);

/*
**	stages.c
*/
void			stages(t_md5 *m);

/*
**	tools.c
*/
uint32_t		b_r(uint32_t b, uint32_t offset);
char			*convert_to_hash(char *in);

/*
**	functions_1.c
*/
u_int32_t		f(u_int32_t x, u_int32_t y, u_int32_t z);
u_int32_t		g(u_int32_t x, u_int32_t y, u_int32_t z);
u_int32_t		h(u_int32_t x, u_int32_t y, u_int32_t z);
u_int32_t		i(u_int32_t x, u_int32_t y, u_int32_t z);

#endif
