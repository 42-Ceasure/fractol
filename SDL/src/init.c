/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:55:44 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:55:45 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void		init_vals(t_env *w)
{
	w->color_mod = 1;
	w->fractal_mod = 1;
	w->fractal = 1;
	w->mode = 1;
	w->curs = 1;
	w->mode = 1;
	w->zoom = 0.5;
	w->posx = 0;
	w->posy = 0;
	w->crealp = -0.8;
	w->cimg = 0.2;
	w->end = 100;
}

void		init_color(t_env *w, char **av)
{
	if (!strcmp(av[2], "1"))
		w->color_mod = 1;
	if (!strcmp(av[2], "2"))
		w->color_mod = 2;
	if (!strcmp(av[2], "3"))
		w->color_mod = 3;
	if (!strcmp(av[2], "4"))
		w->color_mod = 4;
	if (!strcmp(av[2], "5"))
		w->color_mod = 5;
	if (!strcmp(av[2], "6"))
		w->color_mod = 6;
}

void		init_fractal(t_env *w, char **av)
{
	if (!ft_strcmp(av[1], "Julia") || !strcmp(av[1], "1"))
		w->fractal = 1;
	if (!ft_strcmp(av[1], "Mandelbrot") || !strcmp(av[1], "2"))
		w->fractal = 2;
	if (!ft_strcmp(av[1], "Burning_ship") || !strcmp(av[1], "3"))
		w->fractal = 3;
	if (!ft_strcmp(av[1], "Multibrot") || !strcmp(av[1], "4"))
		w->fractal = 4;
	if (!ft_strcmp(av[1], "Heart") || !strcmp(av[1], "5"))
		w->fractal = 5;
}

int			init_sdl(t_env *w)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (-1);
	w->win = SDL_CreateWindow(NAME, SDL_WINDOWPOS_CENTERED,
									SDL_WINDOWPOS_CENTERED,
									WIDTH,
									HEIGHT,
									SDL_WINDOW_BORDERLESS);
	w->rdr = SDL_CreateRenderer(w->win, -1, SDL_RENDERER_ACCELERATED |
											SDL_RENDERER_PRESENTVSYNC);
	w->pix = (Uint32 *)malloc(sizeof(Uint32) * WIDTH * HEIGHT);
	w->txtr = SDL_CreateTexture(w->rdr, SDL_PIXELFORMAT_ARGB8888,
										SDL_TEXTUREACCESS_STREAMING,
										WIDTH,
										HEIGHT);
	return (0);
}
