/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 19:08:26 by imaltsev          #+#    #+#             */
/*   Updated: 2018/12/19 19:08:29 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

t_flags	*get_flags(t_flags *flags, int ac, char **av, int *i)
{
	int j;

	while (*i < ac && av[*i][0] == '-')
	{
		j = 1;
		while (av[*i][j] != '\0')
		{
			if (av[*i][j] == 'r')
				flags->r = 1;
			else if (av[*i][j] == 'p')
				flags->p = 1;
			else if (av[*i][j] == 'q')
				flags->q = 1;
			else if (av[*i][j] == 's')
				flags->s = 1;
			else
			{
				flag_error(av[*i][j]);
				return (0);
			}
			j++;
		}
		(*i)++;
	}
	return (flags);
}

void	program_manager(int ac, char **av)
{
	int			i;
	t_flags		*f;

	i = 2;
	f = (t_flags *)ft_memalloc(sizeof(t_flags));
	if (!get_flags(f, ac, av, &i))
	{
		free(f);
		return ;
	}
	if (f->p == 1 || i == ac)
		print_hash_from_stdin(av[1], *f);
	if (f->s == 1)
	{
		if (i < ac)
			print_hash_from_str(av[1], av[i++], *f);
		else
			string_error();
	}
	while (i < ac)
		print_hash_from_file(av[1], av[i++], *f);
	free(f);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		argc_error();
	else if (!ft_strcmp(argv[1], "md5") || !ft_strcmp(argv[1], "sha256"))
		program_manager(argc, argv);
	else
		comand_error(argv[1]);
	return (0);
}
