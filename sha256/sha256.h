/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:02:31 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 20:02:34 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHA256_H
# define FT_SHA256_H
# include <stdio.h>
# include <stdlib.h>
# include "../libft/mylibft.h"

uint32_t		g_A;
uint32_t		g_B;
uint32_t		g_C;
uint32_t		g_D;
uint32_t		g_E;
uint32_t		g_F;
uint32_t		g_G;
uint32_t		g_H;
uint32_t		g_W[64];
u_int32_t		g_K[64];

typedef	struct	s_string
{
	char	*str;
	size_t	size;
}				t_string;

/*
**	sha256.c
*/
uint8_t			*sha256(char *str_input);

/*
**	init_sha256.c
*/
void			init_sha256(t_string *W, char *str_input);

/*
**	prepare_g_W.c
*/
void			prepare_g_W(t_string *W);

/*
**	tools_sha265.c
*/
uint32_t		reverse_4_bytes(uint32_t b);
uint64_t		swap_8_bytes(uint64_t b);
uint32_t		rotr(uint32_t b, uint32_t offset);

#endif
