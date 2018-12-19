/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:14:39 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/08 14:14:40 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_helper(int i, int len, const char *s, char *str)
{
	int		k;

	k = 0;
	while (i <= len)
	{
		str[k] = s[i];
		i++;
		k++;
	}
	str[k] = '\0';
	return (str);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		len--;
	if (len == -1 && (str = (char *)malloc(sizeof(str) * 0)) != NULL)
	{
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	if (!s || len + i == 0 || len - i == 0 || ft_strnew(len - i + 1) == NULL)
		return (NULL);
	str = ft_strnew(len - i + 1);
	return (ft_helper(i, len, s, str));
}
