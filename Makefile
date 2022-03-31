SRCS = so_long.c check_error.c get_next_line.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LINKMLX = -lmlx -framework OpenGL -framework AppKit
PRINTFPATH = printf/
LIBFTPATH = libft/
PRINTF = printf/libftprintf.a
LIBFT = libft/libft.a

NAME = so_long

all:	$(NAME) $(PRINTF) $(LIBFT)

$(NAME): $(SRCS) $(PRINTF) $(LIBFT)
		$(CC) $(SRCS) $(LINKMLX) $(PRINTF) $(LIBFT) -o $(NAME)

$(PRINTF):
		@make -C $(PRINTFPATH)

$(LIBFT):
		@make -C $(LIBFTPATH)

clean:	
		@make clean -C $(PRINTFPATH)
		@make clean -C $(LIBFTPATH)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all