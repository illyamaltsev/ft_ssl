/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:13:45 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:13:58 by imaltsev         ###   ########.fr       */
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

void	print_hash(char *command, char *line)
{
	uint8_t *hash;

	hash = 0;
	if (!ft_strcmp(command, "md5") || !ft_strcmp(command, "MD5"))
	{
		hash = ft_md5(line);
		ft_print_hash(hash, 16);
		free(hash);
	}
	else
	{
		hash = sha256(line);
		ft_print_hash(hash, 32);
		free(hash);
	}
}

void	print_hash_from_stdin(char *command, t_flags f)
{
	char	*line;

	ft_get_all(0, &line);
	if (f.p == 1)
		ft_printf("%s", line);
	print_hash(command, line);
	ft_printf("\n");
	free(line);
}

void	print_hash_from_str(char *command, char *arg, t_flags f)
{
	if (f.q == 1)
		print_hash(command, arg);
	else
	{
		if (f.r == 1)
		{
			print_hash(command, arg);
			ft_printf(" \"%s\"", arg);
		}
		else
		{
			ft_printf("%s (\"%s\") = ", ft_gobig(command), arg);
			print_hash(command, arg);
		}
	}
	ft_printf("\n");
}

void	print_hash_from_file(char *command, char *arg, t_flags f)
{
	char	*line;
	int		fd;

	fd = open(arg, O_RDWR);
	if (fd == -1)
		file_error(arg);
	else
	{
		ft_get_all(fd, &line);
		if (f.q == 1)
			print_hash(command, line);
		else if (f.r == 1)
		{
			print_hash(command, line);
			ft_printf(" %s", arg);
		}
		else
		{
			ft_printf("%s (%s) = ", ft_gobig(command), arg);
			print_hash(command, line);
		}
		ft_printf("\n");
		free(line);
	}
	close(fd);
}
