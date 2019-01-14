NAME = ft_ssl

OBJSRC = main.c print.c error.c tools.c
MD5 = md5.c md5_functions.c md5_init.c md5_stages.c md5_tools.c
SHA256 = sha256.c sha256_init.c sha256_prepare_g_w.c sha256_tools.c

OBJC = $(OBJSRC) $(MD5:md5%.c=md5/md5%.c) $(SHA256:sha256%.c=sha256/sha256%.c)
OBJO = $(OBJSRC:.c=.o) $(MD5:.c=.o) $(SHA256:.c=.o)
CFLAGS = -Wall -Werror -Wextra
LIBDIR = libft

all: $(NAME)

$(NAME):
	@make -C $(LIBDIR)
	@gcc $(CFLAGS) $(OBJC) -c $< -I includes
	@gcc $(CFLAGS) $(OBJO) -o $(NAME) $(LIBDIR)/libft.a
	@echo "\033[0;32mft_ssl: make: done"

clean:
	@make clean -C $(LIBDIR)
	@rm -f $(OBJO)
	@echo "\033[0;31mft_ssl: clean: done"

fclean: clean
	@rm -f $(NAME) libft/libft.a
	@echo "\033[0;31mlibft: fclean: done"
	@echo "\033[0;31mft_ssl: fclean: done"

re: fclean all
