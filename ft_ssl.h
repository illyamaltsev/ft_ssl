/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:27:09 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:27:10 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_FT_SSL_H
# define FT_SSL_FT_SSL_H
# include "sha256/sha256.h"
# include "md5/md5.h"
# include <fcntl.h>

typedef struct	s_flags{
	char r;
	char p;
	char q;
	char s;
}				t_flags;

typedef uint8_t *(*t_hash_function)(char *);

/*
**	print.c
*/
void			print_hash_from_stdin(char *command, t_flags f);
void			print_hash_from_str(char *command, char *arg, t_flags f);
void			print_hash_from_file(char *command, char *arg, t_flags f);

/*
**	error.c
*/
void			file_error(char *file, char *command);
void			string_error(char *command);
void			flag_error(char f);
void			comand_error(char *command);
void			argc_error(void);

/*
**	tools.c
*/
void			ft_print_hash(uint8_t *b, size_t len);

#endif
