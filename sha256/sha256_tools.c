/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha256_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 20:09:23 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 20:09:24 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sha256.h"

uint32_t	reverse_4_bytes(uint32_t b)
{
	return (b >> 24 | ((b >> 8) & 0xff00) | ((b << 8) & 0xff0000) | b << 24);
}

uint64_t	swap_8_bytes(uint64_t b)
{
	return ((uint64_t)reverse_4_bytes(b) << 32
			| (uint64_t)reverse_4_bytes(b >> 32));
}

uint32_t	rotr(uint32_t b, uint32_t offset)
{
	return ((b >> offset) | (b << (32 - offset)));
}
