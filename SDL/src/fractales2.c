/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:53:52 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 09:53:53 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void			calcmdb(t_env *w)
{
	while (w->i < w->end)
	{
		w->oreal = w->nreal;
		w->oimg = w->nimg;
		w->nreal = w->oreal * w->oreal - w->oimg * w->oimg + w->pr + w->crealp;
		w->nimg = 2 * w->oreal * w->oimg + w->pi + w->cimg;
		if ((w->nreal * w->nreal + w->nimg * w->nimg) > 4)
			break ;
		w->i++;
	}
}

void			draw_mdb(t_env *w)
{
	w->x = 0;
	while (w->x < WIDTH)
	{
		w->y = 0;
		while (w->y < HEIGHT)
		{
			w->pr = 1.5 * (w->x - WIDTH / 2) /
			(0.5 * w->zoom * WIDTH) + w->posx;
			w->pi = (w->y - HEIGHT / 2) /
			(0.5 * w->zoom * HEIGHT) + w->posy;
			w->nreal = 0;
			w->nimg = 0;
			w->oreal = 0;
			w->oimg = 0;
			w->i = 0;
			calcmdb(w);
			w->color = color(w);
			mlx_pixel_wput(w, w->x, w->y);
			w->y++;
		}
		w->x++;
	}
}

void			calcmb3(t_env *w)
{
	while (w->i < w->end)
	{
		w->oreal = w->nreal;
		w->oimg = w->nimg;
		w->nreal = (w->oreal * w->oreal * w->oreal * w->oreal) -
		4 * w->oreal * w->oimg * w->oimg + w->pr;
		w->nimg = -(w->oimg * w->oimg * w->oimg) +
		4 * w->oreal * w->oreal * w->oimg + w->pi;
		if ((w->nreal * w->nreal + w->nimg * w->nimg) > 4)
			break ;
		w->i++;
	}
}

void			draw_multbrot3(t_env *w)
{
	w->x = 0;
	while (w->x < WIDTH)
	{
		w->y = 0;
		while (w->y < HEIGHT)
		{
			w->pr = 1.5 * (w->x - WIDTH / 2) /
			(0.5 * w->zoom * WIDTH) + w->posx;
			w->pi = (w->y - HEIGHT / 2) /
			(0.5 * w->zoom * HEIGHT) + w->posy;
			w->nreal = 0;
			w->nimg = 0;
			w->oreal = 0;
			w->oimg = 0;
			w->i = 0;
			calcmb3(w);
			w->color = color(w);
			mlx_pixel_wput(w, w->x, w->y);
			w->y++;
		}
		w->x++;
	}
}
