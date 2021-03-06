/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:50:15 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:50:17 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "md5.h"

uint32_t	b_r(uint32_t b, uint32_t offset)
{
	return ((b << offset) | (b >> (32 - offset)));
}
