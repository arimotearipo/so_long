# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wwan-taj <wwan-taj@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 17:10:51 by wwan-taj          #+#    #+#              #
#    Updated: 2022/04/09 14:27:06 by wwan-taj         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PREGAME = pregame/checkelements.c pregame/checkerror.c pregame/checkfilename.c \
			pregame/get_next_line.c pregame/getcolandrow.c pregame/getinfo.c \
			pregame/init.c pregame/isrectangle.c pregame/iswallenclosed.c \
			pregame/parsemap.c \

GAME = 	game/animate.c game/drawmap.c game/hookfunctions.c \
		game/setsprite.c game/stepdisplay.c \

POSTGAME = 	postgame/exitgame.c postgame/freeall.c 

MAIN =		main.c

INCLUDES = $(GAMEPATH) $(POSTGAMEPATH) $(PREGAMEPATH)
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
		$(CC) $(SRCS) $(LINKMLX) $(PRINTF) $(LIBFT) $(PREGAME) $(GAME) $(POSTGAME) $(MAIN) -o $(NAME)

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