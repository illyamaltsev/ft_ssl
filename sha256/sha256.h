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

uint32_t		g_a;
uint32_t		g_b;
uint32_t		g_c;
uint32_t		g_d;
uint32_t		g_e;
uint32_t		g_f;
uint32_t		g_g;
uint32_t		g_h;
uint32_t		g_w[64];
u_int32_t		g_k[64];

typedef	struct	s_string
{
	char	*str;
	char	*tofree;
	size_t	size;
}				t_string;

/*
**	ft_sha256.c
*/
uint8_t			*ft_sha256(char *str_input);

/*
**	init_sha256.c
*/
void			init_sha256(t_string *w, char *str_input);

/*
**	prepare_g_w.c
*/
char			prepare_g_w(t_string *w);

/*
**	tools_sha265.c
*/
uint32_t		reverse_4_bytes(uint32_t b);
uint64_t		swap_8_bytes(uint64_t b);
uint32_t		rotr(uint32_t b, uint32_t offset);

#endif
