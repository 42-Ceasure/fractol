/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:55:59 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:56:00 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void		ft_1(t_env *w)
{
	if (w->mode == 1)
		w->color_mod = 1;
	if (w->mode == 2)
		w->fractal_mod = 1;
	if (w->mode == 3)
		w->fractal = 1;
}

void		shape(t_env *w)
{
	if (w->inkeys[SDL_SCANCODE_W])
		shape_i_pos(w);
	if (w->inkeys[SDL_SCANCODE_S])
		shape_i_neg(w);
	if (w->inkeys[SDL_SCANCODE_A])
		shape_r_neg(w);
	if (w->inkeys[SDL_SCANCODE_D])
		shape_r_pos(w);
}

void		move(t_env *w)
{
	if (w->inkeys[SDL_SCANCODE_UP])
		mv_up(w);
	if (w->inkeys[SDL_SCANCODE_DOWN])
		mv_down(w);
	if (w->inkeys[SDL_SCANCODE_LEFT])
		mv_left(w);
	if (w->inkeys[SDL_SCANCODE_RIGHT])
		mv_right(w);
}

void		choose_mode(t_env *w)
{
	if (w->inkeys[SDL_SCANCODE_C])
		w->mode = 1;
	if (w->inkeys[SDL_SCANCODE_X])
		w->mode = 2;
	if (w->inkeys[SDL_SCANCODE_Z])
		w->mode = 3;
	if (w->inkeys[SDL_SCANCODE_1])
		ft_1(w);
	if (w->inkeys[SDL_SCANCODE_2])
		ft_2(w);
	if (w->inkeys[SDL_SCANCODE_3])
		ft_3(w);
	if (w->inkeys[SDL_SCANCODE_4])
		ft_4(w);
	if (w->inkeys[SDL_SCANCODE_5])
		ft_5(w);
	if (w->inkeys[SDL_SCANCODE_6])
		ft_6(w);
}

void		key_events(t_env *w)
{
	shape(w);
	move(w);
	choose_mode(w);
	if (w->inkeys[SDL_SCANCODE_MINUS])
		iteration_less(w);
	if (w->inkeys[SDL_SCANCODE_EQUALS])
		iteration_more(w);
	if (w->inkeys[SDL_SCANCODE_M])
		zoomin(w);
	if (w->inkeys[SDL_SCANCODE_N])
		zoomout(w);
	if (w->inkeys[SDL_SCANCODE_V])
		setcursor(w);
	if (w->inkeys[SDL_SCANCODE_P])
	{
		w->posx = 0;
		w->posy = 0;
	}
}
