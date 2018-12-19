/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:37:54 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:37:56 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

u_int32_t	F(u_int32_t x, u_int32_t y, u_int32_t z)
{
	return ((x & y) | (~x & z));
}

u_int32_t	G(u_int32_t x, u_int32_t y, u_int32_t z)
{
	return ((x & z) | (~z & y));
}

u_int32_t	H(u_int32_t x, u_int32_t y, u_int32_t z)
{
	return (x ^ y ^ z);
}

u_int32_t	I(u_int32_t x, u_int32_t y, u_int32_t z)
{
	return (y ^ (~z | x));
}
