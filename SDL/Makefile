# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cglavieu <cglavieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/16 14:40:47 by cglavieu          #+#    #+#              #
#    Updated: 2015/05/19 19:11:17 by cglavieu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re

CC = gcc

CFLAG = -Wall -Wextra -Werror

NAME = ../fractol_SDL

SRCDIR=		./src/
SRC=		color.c\
			main.c\
			shape.c\
			draw.c\
			mlx_core.c\
			zoom.c\
			init.c\
			mouse_events.c\
			key_events.c\
			moves.c\
			key_events2.c\
			color2.c\
			fractales.c\
			fractales2.c\
			fractales3.c

SRCFIL=		$(addprefix $(SRCDIR),$(SRC))

OBJ = $(SRC:.c=.o)

OBJDIR = ./obj/

LIBFT = ./lib/libft/

LIBFTEXE = $(LIBFT)libft.a

SDL_FW = ./lib/SDL2.framework/SDL2

all:    $(NAME)

$(NAME): $(addprefix $(OBJDIR),$(OBJ)) $(LIBFTEXE)
		@$(CC) $(CFLAG) -L $(LIBFT) -lft -o $(NAME)\
		$(addprefix $(OBJDIR), $(OBJ)) $(SDL_FW)

$(OBJDIR)%.o: $(SRCDIR)%.c
		@mkdir -p $(OBJDIR)
		@$(CC) $(CFLAG) -I . -I $(LIBFT) -o $@ -c $<

$(LIBFTEXE): $(LIBFT)
		@make -k -s -C $(LIBFT)	

clean:	
		@rm -Rf  $(OBJDIR)
		@make -C $(LIBFT) clean

fclean: 
		@rm -Rf  $(OBJDIR)	
		@rm -f $(NAME)
		@make -C $(LIBFT) fclean

re:		fclean all

