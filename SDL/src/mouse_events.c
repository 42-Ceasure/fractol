/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:56:43 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:56:44 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void		wheel_events(t_env *w)
{
	if (WHEEL.y > 0)
		zoomin(w);
	if (WHEEL.y < 0)
		zoomout(w);
}

void		motion_events(t_env *w)
{
	static double x;
	static double y;

	if (w->fractal_mod == 2)
	{
		w->crealp = (((double)MOUSE.x - WIDTH / 2) / (WIDTH / 2));
		w->cimg = (((double)MOUSE.y - HEIGHT / 2) / (HEIGHT / 2)) / 0.7;
	}
	w->xsouris = ((double)MOUSE.x - WIDTH / 2) * 2 / (WIDTH * w->zoom) * -1;
	w->ysouris = ((double)MOUSE.y - HEIGHT / 2) * 2 / (HEIGHT * w->zoom) * -1;
	if (w->fractal_mod == 3)
	{
		x = w->posx - w->xsouris;
		y = w->posy - w->ysouris;
		w->fractal_mod = 4;
	}
	if (w->fractal_mod == 4)
	{
		w->posx = w->xsouris + x;
		w->posy = w->ysouris + y;
	}
}
