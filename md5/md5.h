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

typedef struct	t_abcdTX
{
	uint32_t	A;
	uint32_t	B;
	uint32_t	C;
	uint32_t	D;
	uint32_t	T[65];
	uint32_t	*X;
	char		*str;
	size_t		size;
}				t_abcdTX;

/*
**	md5.c
*/
uint8_t			*ft_md5(char *str_input);

/*
**	init.c
*/
void			init_md5(t_abcdTX *m, char *str_input);
void			init_abcd(t_abcdTX *abcd);

/*
**	stages.c
*/
void			stages(t_abcdTX *m);

/*
**	tools.c
*/
uint32_t		b_r(uint32_t b, uint32_t offset);
char			*convert_to_hash(char *in);

/*
**	functions_1.c
*/
u_int32_t		F(u_int32_t x, u_int32_t y, u_int32_t z);
u_int32_t		G(u_int32_t x, u_int32_t y, u_int32_t z);
u_int32_t		H(u_int32_t x, u_int32_t y, u_int32_t z);
u_int32_t		I(u_int32_t x, u_int32_t y, u_int32_t z);

#endif
