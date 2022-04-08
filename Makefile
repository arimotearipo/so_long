# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 17:10:51 by wwan-taj          #+#    #+#              #
#    Updated: 2022/04/08 12:29:13 by wwan-taj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.c checkerror.c get_next_line.c getinfo.c exitgame.c \
		parsemap.c drawmap.c init.c setsprite.c isrectangle.c \
		getcolandrow.c checkfilename.c checkelements.c iswallenclosed.c \
		hookfunctions.c freeall.c  getcolour.c 	animate.c  stepdisplay.c\
		
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

LINKMLX = -lmlx -framework OpenGL -framework AppKit
PRINTFPATH = printf/
LIBFTPATH = libft/
PRINTF = printf/libftprintf.a
LIBFT = libft/libft.a

NAME = so_long

all:	$(LIBFT) $(PRINTF) $(NAME)

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

map: re
	./$(NAME) map.ber

re:		fclean all