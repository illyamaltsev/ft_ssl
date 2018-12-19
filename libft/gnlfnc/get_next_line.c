/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:49:27 by imaltsev          #+#    #+#             */
/*   Updated: 2017/12/26 18:01:47 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_realloc(char *str, int n)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	tmp = ft_strnew(n);
	while (str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}

static void		ft_save(t_gnl *lst, char **line, char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (lst->buf[i] != '\n')
		i++;
	i++;
	while (lst->buf[i] != '\0')
		lst->buf[j++] = lst->buf[i++];
	while (lst->buf[j] != '\0')
		lst->buf[j++] = '\0';
	*line = str;
}

static int		ft_read(int fd, char **line, t_gnl *lst, int i)
{
	int		j;
	int		b;
	char	*str;

	str = ft_strnew(BUFF_SIZE + 1);
	while ((j = 0) == 0 && !(ft_memchr(lst->buf, '\n', BUFF_SIZE + 1)))
	{
		while (lst->buf[j] != '\0')
			str[i++] = lst->buf[j++];
		if ((b = read(fd, &lst->buf, BUFF_SIZE)) == 0 && ft_strlen(str) == 0)
			free(str);
		if (b == 0 && ft_strlen(str) == 0)
			return (0);
		if (b == 0 && (*line = str) == str)
		{
			ft_bzero(lst->buf, BUFF_SIZE + 1);
			return (1);
		}
		lst->buf[b] = '\0';
		str = ft_realloc(str, b + i + 1);
	}
	while (lst->buf[j] != '\n')
		str[i++] = lst->buf[j++];
	ft_save(lst, line, str);
	return (1);
}

static t_gnl	*find_fd(int fd, t_gnl *lst)
{
	t_gnl *new_gnl;

	while (lst->next)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	if (lst->fd == fd)
		return (lst);
	new_gnl = malloc(sizeof(t_gnl));
	new_gnl->fd = fd;
	ft_bzero(new_gnl->buf, BUFF_SIZE + 1);
	new_gnl->next = NULL;
	new_gnl->start = lst->start;
	lst->next = new_gnl;
	return (new_gnl);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl *lst = NULL;

	if (line == NULL || fd < 0 || read(fd, NULL, 0) < 0 ||
		BUFF_SIZE <= 0)
		return (-1);
	if (lst == NULL)
	{
		lst = malloc(sizeof(t_gnl));
		lst->fd = fd;
		lst->next = NULL;
		lst->start = lst;
		ft_bzero(lst->buf, BUFF_SIZE + 1);
		return (ft_read(fd, line, lst, 0));
	}
	lst = find_fd(fd, lst->start);
	return (ft_read(fd, line, lst, 0));
}
