/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 10:14:36 by imaltsev          #+#    #+#             */
/*   Updated: 2018/01/11 10:14:43 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrnew(int i, int j)
{
	int		k;
	char	**arr;

	k = 0;
	arr = (char **)malloc(sizeof(char *) * (i + 1));
	arr[i] = NULL;
	while (arr[k] != NULL)
		arr[k++] = ft_strnew(j);
	return (arr);
}
