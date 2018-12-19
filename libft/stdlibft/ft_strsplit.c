/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:05:26 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/08 16:05:27 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *s, char c)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			while (s[i++] != c && s[i] != '\0')
				i++;
			n++;
		}
	}
	return (n);
}

static char	**ft_create_arr(const char *s, char c,
	int nb_word, int *lens)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	if (!(tab = (char **)malloc(sizeof(*tab) * nb_word + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			if (!(tab[j] = (char *)malloc(sizeof(**tab) * lens[j] + 1)))
				return (NULL);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit(const char *s, char c)
{
	int i;
	int count_word;
	int len;
	int *lens;

	if (!s || !c)
		return (NULL);
	if ((lens = (int *)malloc(sizeof(lens) * ft_count_word(s, c))) == NULL)
		return (NULL);
	i = 0;
	count_word = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			len = 0;
			while (s[i++] != c && s[i] != '\0')
				len++;
			lens[count_word] = len;
			count_word++;
		}
	}
	return (ft_create_arr(s, c, count_word, lens));
}
