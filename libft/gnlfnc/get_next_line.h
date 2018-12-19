/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:38:10 by imaltsev          #+#    #+#             */
/*   Updated: 2017/11/28 13:38:17 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"

typedef struct			s_gnl
{
	char				buf[BUFF_SIZE + 1];
	int					fd;
	struct s_gnl		*next;
	struct s_gnl		*start;
}						t_gnl;

int						get_next_line(const int fd, char **line);

#endif
