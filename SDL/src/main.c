/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:56:19 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:56:19 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void	consignes(t_env *w)
{
	w->fractal = 1;
	ft_putendl("use ./fractol <name of set>");
	ft_putendl("sets  : - Julia (1)");
	ft_putendl("        - Mandelbrot (2)");
	ft_putendl("        - Burning_ship (3)");
	ft_putendl("        - Multibrot (4)");
	ft_putendl("        - Heart (5)\n");
	ft_putendl("binds : - C, X, Z to change of mode");
	ft_putendl("        - 1, 2, 3, 4, 5 to switch");
	ft_putendl("        beetween elements of the mode");
	ft_putendl("        - V to enable / disable cursor");
	ft_putendl("        - W, A, S, D  to change the shape");
	ft_putendl("        of Julia");
	ft_putendl("        - UP, DOWN, RIGHT, LEFT to move");
	ft_putendl("        - '+' and '-' to increase / decrease");
	ft_putendl("        max iterations");
	ft_putendl("        - M, N, or Scroll UP/DOWN to zoom in/out");
	ft_putendl("        - P to reset central position");
}

int		main(int ac, char **av)
{
	t_env *w;

	w = (t_env *)malloc(sizeof(t_env));
	if (ac == 1)
		write(1, "not enough arguments, fractale set to 1.\n", 41);
	init_vals(w);
	if (av[1])
		init_fractal(w, av);
	if (av[2])
		init_color(w, av);
	if (init_sdl(w) != 0)
	{
		write(1, "cannot intitialize SDL2\n", 24);
		return (0);
	}
	dance(w);
	return (0);
}
