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

void	print_hash_function(t_hash_function hf, char *line, size_t len)
{
	uint8_t *hash;

	hash = hf(line);
	ft_print_hash(hash, len);
	free(hash);
}

void	print_tuner(char *command, char *line)
{
	if (!ft_strcmp(command, "md5"))
		print_hash_function(ft_md5, line, 16);
	else
		print_hash_function(ft_sha256, line, 32);
}

void	print_hash_from_stdin(char *command, t_flags f)
{
	char	*line;

	ft_get_all(0, &line);
	if (f.p == 1)
		ft_printf("%s", line);
	print_tuner(command, line);
	ft_printf("\n");
	free(line);
}

void	print_hash_from_str(char *command, char *arg, t_flags f)
{
	if (f.q == 1)
		print_tuner(command, arg);
	else
	{
		if (f.r == 1)
		{
			print_tuner(command, arg);
			ft_printf(" \"%s\"", arg);
		}
		else
		{
			ft_printf("%s (\"%s\") = ", ft_gobig(command), arg);
			ft_golow(command);
			print_tuner(command, arg);
		}
	}
	ft_printf("\n");
}

void	print_hash_from_file(char *command, char *arg, t_flags f)
{
	char	*line;
	int		fd;

	if ((fd = open(arg, O_RDWR)) == -1)
		file_error(arg, command);
	else
	{
		ft_get_all(fd, &line);
		if (f.q == 1)
			print_tuner(command, line);
		else if (f.r == 1)
		{
			print_tuner(command, line);
			ft_printf(" %s", arg);
		}
		else
		{
			ft_printf("%s (%s) = ", ft_gobig(command), arg);
			ft_golow(command);
			print_tuner(command, line);
		}
		ft_printf("\n");
		free(line);
	}
	close(fd);
}
