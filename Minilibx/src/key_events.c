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

void		shape(int keycode, t_env *w)
{
	if (keycode == 13)
		shape_i_pos(w);
	if (keycode == 0)
		shape_i_neg(w);
	if (keycode == 1)
		shape_r_neg(w);
	if (keycode == 2)
		shape_r_pos(w);
}

void		move(int keycode, t_env *w)
{
	if (keycode == 126)
		mv_up(w);
	if (keycode == 125)
		mv_down(w);
	if (keycode == 123)
		mv_left(w);
	if (keycode == 124)
		mv_right(w);
}

void		choose_mode(int keycode, t_env *w)
{
	if (keycode == 8)
		w->mode = 1;
	if (keycode == 7)
		w->mode = 2;
	if (keycode == 6)
		w->mode = 3;
	if (keycode == 18)
		ft_1(w);
	if (keycode == 19)
		ft_2(w);
	if (keycode == 20)
		ft_3(w);
	if (keycode == 21)
		ft_4(w);
	if (keycode == 23)
		ft_5(w);
	if (keycode == 22)
		ft_6(w);
}

int			key_hook(int keycode, t_env *w)
{
	shape(keycode, w);
	move(keycode, w);
	choose_mode(keycode, w);
	if (keycode == 53)
		exit(0);
	if (keycode == 78)
		iteration_less(w);
	if (keycode == 69)
		iteration_more(w);
	if (keycode == 46)
		zoomin(w);
	if (keycode == 45)
		zoomout(w);
	if (keycode == 35)
	{
		w->posx = 0;
		w->posy = 0;
	}
	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->data = mlx_get_data_addr(w->img, &(w->bpp), &(w->s_line),
								&(w->endian));
	expose_hook(w);
	return (0);
}
