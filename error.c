/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:25:22 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:25:23 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	file_error(char *file)
{
	ft_printf("ft_ssl: %s: No such file or directory\n", file);
}

void	string_error(void)
{
	ft_printf("ft_ssl: option requires an argument - s\n"
						"usage: md5 [-pqrs] [command args]\n");
}

void	flag_error(char f)
{
	ft_printf("ft_ssl: illegal option - '%c'\n"
						"usage: md5 [-pqrs] [command args]\n"
						"-p, echo STDIN to STDOUT and append"
						" the checksum to STDOUT.\n"
						"-q, quiet mode.\n"
						"-r, reverse the format of the output.\n"
						"-s, print the sum of the given string.\n", f);
}

void	comand_error(char *command)
{
	ft_printf("ft_ssl: Error: '%s' is an invalid command.\n"
						"\nStandard commands:\n"
						"\nMessage Digest commands:\n"
						"md5\n"
						"sha256\n"
						"\nCipher commands:\n", command);
}

void	argc_error(void)
{
	ft_printf("usage: ft_ssl command [command opts] [command args]\n");
}
