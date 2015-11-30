
.PHONY: clean, fclean, re

NAME = fractol_MLX fractol_SDL

MLX = ./Minilibx/

SDL = ./SDL/

all: $(NAME)

$(NAME):
	@make -C $(MLX)
	@make -C $(SDL)
	@ln -fs fractol_MLX fractol

clean:	
			@make -C $(MLX) clean
			@make -C $(SDL) clean

fclean: 
			@make -C $(MLX) fclean
			@make -C $(SDL) fclean
			@rm -f fractol

re:		fclean all

