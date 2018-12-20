NAME = ft_ssl

OBJSRC = main.c print.c error.c
MD5 = md5.c md5_functions.c md5_init.c md5_stages.c md5_tools.c
SHA256 = sha256.c sha256_init.c sha256_prepare_g_w.c sha256_tools.c



OBJC = $(OBJSRC) $(MD5:md5%.c=md5/md5%.c) $(SHA256:sha256%.c=sha256/sha256%.c)
OBJO = $(OBJSRC:.c=.o) $(MD5:.c=.o) $(SHA256:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBDIR = libft

all: $(NAME)

$(NAME):
	make -c $(LIBDIR)
	gcc $(CFLAGS) $(OBJC) -c $< -i includes
	gcc $(CFLAGS) $(OBJO) -o $(NAME) $(LIBDIR)/libft.a
	echo "make : done"

clean:
	make clean -c $(LIBDIR)
	rm -f $(OBJO)

fclean: clean
	make fclean -c $(LIBDIR)
	rm -f $(NAME)

re: fclean all