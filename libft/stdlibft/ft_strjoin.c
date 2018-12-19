/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:13:25 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/08 17:13:27 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;
	int		i;
	int		j;

	j = 0;
	if (!s1 || !s2)
		return (NULL);
	fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!fresh)
		return (NULL);
	while (s1[j] != '\0')
	{
		fresh[j] = s1[j];
		j++;
	}
	i = j;
	j = 0;
	while (s2[j] != '\0')
	{
		fresh[i] = s2[j];
		i++;
		j++;
	}
	fresh[i] = '\0';
	return (fresh);
}
