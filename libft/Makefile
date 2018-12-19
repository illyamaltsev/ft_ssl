# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imaltsev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 19:28:55 by imaltsev          #+#    #+#              #
#    Updated: 2018/01/15 19:28:57 by imaltsev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


OBJLIBFTC = ft_lstnew.c ft_striter.c ft_strnequ.c ft_atoi.c ft_itoa.c\
			ft_putchar.c ft_striteri.c ft_strcat.c ft_strjoin.c ft_strnstr.c\
			ft_strnew.c ft_bzero.c ft_lstadd.c ft_memalloc.c ft_putchar_fd.c\
			ft_memccpy.c ft_putendl.c ft_strchr.c ft_strlcat.c ft_strrchr.c\
			ft_lstdel.c ft_memchr.c ft_putendl_fd.c ft_strclr.c\
			ft_strlen.c ft_strsplit.c ft_isalnum.c ft_lstdelone.c ft_memcmp.c\
			ft_putnbr.c ft_strcmp.c ft_strmap.c ft_strstr.c ft_isalpha.c\
			ft_lstiter.c ft_memcpy.c ft_putnbr_fd.c ft_strcpy.c ft_strmapi.c\
			ft_strsub.c ft_isascii.c ft_lstmap.c ft_memdel.c ft_putstr.c ft_strdel.c\
			ft_strncat.c ft_strtrim.c ft_isdigit.c ft_memmove.c ft_putstr_fd.c\
			ft_strdup.c ft_strncmp.c ft_tolower.c ft_isprint.c ft_memset.c\
			ft_strequ.c ft_strncpy.c ft_toupper.c ft_putnstr.c ft_itoa_base.c
OBJPRINTFC = ft_printf.c ft_stdfuncs.c ft_corect.c ft_wchar_t_char.c ft_wchar_t_str.c\
			ft_parsing.c ft_format_openers.c ft_corect_width_precision.c
OBJMYC = ft_fill_array.c ft_rot_13.c ft_sqrt.c ft_arrnew.c ft_tenton.c ft_gobig.c\
		 	ft_foreach.c ft_isstrofdigit.c ft_realloc_free.c ft_get_all.c
OBJGNLC = get_next_line.c
OBJC = $(OBJLIBFTC:ft_%.c=stdlibft/ft_%.c) $(OBJPRINTFC:ft_%.c=printffnc/ft_%.c) $(OBJMYC:ft_%.c=myfnc/ft_%.c) $(OBJGNLC:%.c=gnlfnc/%.c)
OBJO = $(OBJLIBFTC:.c=.o) $(OBJPRINTFC:.c=.o) $(OBJMYC:.c=.o) $(OBJGNLC:.c=.o)
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra

$(NAME):
	gcc $(CFLAGS) -c $(OBJC)
	ar rc $(NAME) $(OBJO)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJO)

fclean: clean
	rm -f $(NAME)

re: fclean all
