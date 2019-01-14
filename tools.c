/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:07:36 by imaltsev          #+#    #+#             */
/*   Updated: 2019/01/11 12:07:37 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	ft_print_hash(uint8_t *b, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		ft_printf("%.2x", b[i++]);
}
