/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:46:30 by imaltsev          #+#    #+#             */
/*   Updated: 2018/01/15 14:46:31 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t value, int base)
{
	int			i;
	uintmax_t	n;
	char		*nbr;

	i = 1;
	n = value;
	while ((n /= base) != 0)
		i++;
	nbr = (char*)malloc(sizeof(nbr) * i);
	nbr[i] = '\0';
	while (i-- > 0)
	{
		n = '0';
		if (value % base > 9)
			n = 'a' - 10;
		nbr[i] = (value % base) + n;
		value = value / base;
	}
	return (nbr);
}
