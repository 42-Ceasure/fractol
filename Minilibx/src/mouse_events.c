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

void		selectww(int x, int y, t_env *w)
{
	static double x2;
	static double y2;

	if (w->fractal_mod == 2)
	{
		w->crealp = (((double)x - WIDTH / 2) / (WIDTH / 2)) - 0.5;
		w->cimg = (((double)y - HEIGHT / 2) / (HEIGHT / 2)) / 0.7;
	}
	w->xsouris = ((double)x - WIDTH / 2) * 2 / (WIDTH * w->zoom) * -1;
	w->ysouris = ((double)y - HEIGHT / 2) * 2 / (HEIGHT * w->zoom) * -1;
	if (w->fractal_mod == 3)
	{
		x2 = w->posx - w->xsouris;
		y2 = w->posy - w->ysouris;
		w->fractal_mod = 4;
	}
	if (w->fractal_mod == 4)
	{
		w->posx = w->xsouris + x2;
		w->posy = w->ysouris + y2;
	}
}

void		wheel_events(int button, t_env *w)
{
	if (button == 4)
		zoomin(w);
	if (button == 5)
		zoomout(w);
	usleep(1000);
}

int			motion_hook(int x, int y, t_env *w)
{
	selectww(x, y, w);
	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->data = mlx_get_data_addr(w->img, &(w->bpp), &(w->s_line),
								&(w->endian));
	expose_hook(w);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *w)
{
	(void)x;
	(void)y;
	wheel_events(button, w);
	w->img = mlx_new_image(w->mlx, WIDTH, HEIGHT);
	w->data = mlx_get_data_addr(w->img, &(w->bpp), &(w->s_line),
								&(w->endian));
	expose_hook(w);
	return (0);
}
