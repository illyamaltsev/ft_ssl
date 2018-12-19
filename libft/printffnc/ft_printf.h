/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 13:03:04 by imaltsev          #+#    #+#             */
/*   Updated: 2017/12/29 13:03:06 by imaltsev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include "wchar.h"

typedef struct		s_spcf
{
	char			*spcf;
	int				size;
	char			minus;
	char			plus;
	char			zero;
	char			sharp;
	char			space;
	unsigned int	width;
	int				precision;
	char			conversion;
	char			modifier;
}					t_spcf;

char				*ft_gobig(char *str);
int					ft_count_print_chars(const char *format, int i);
t_spcf				ft_find_all_flags(const char *format, int i);
int					ft_count_format_chars(const char *format, int i);
int					ft_count_formats(const char *format);
char				ft_find_type(const char *format, int i);
char				*ft_corect(char *str, t_spcf spcf, int point);
char				*ft_wstrtoa(wchar_t *wstr);
int					ft_wchtoa(wchar_t ch, char *str, int i);
char				*ft_str(va_list ap, t_spcf *spcf);
char				*ft_int(va_list ap, t_spcf spcf);
char				*ft_base(va_list ap, t_spcf spcf);
char				*ft_char(va_list ap, t_spcf *spcf);
char				*ft_percent_pointer(t_spcf *spcf, va_list ap);
char				*ft_cut_specifier(const char *format, int i);
char				ft_find_conversion(char *spcf);
int					ft_bitsize(unsigned int ch);
char				*ft_corect_precision(char *str, t_spcf spcf);
char				*ft_corect_width(char *str, t_spcf spcf, int i);
int					size(wchar_t *ws, int n, int i);
size_t				ft_wstrlen(wchar_t *wstr);
int					ft_size(wchar_t *ws, int n, int i);
int					ft_printf(const char *format, ...);

#endif
