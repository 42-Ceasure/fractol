/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 06:06:49 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 06:06:50 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void			calcbsh(t_env *w)
{
	while (w->i < w->end)
	{
		w->oreal = w->nreal;
		w->oimg = w->nimg;
		w->nreal = w->oreal * w->oreal - w->oimg * w->oimg + w->pr;
		w->nimg = 2 * fabs(w->oreal * w->oimg) + w->pi;
		if ((w->nreal * w->nreal + w->nimg * w->nimg) > 4)
			break ;
		w->i++;
	}
}

void			draw_bsh(t_env *w)
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
			w->nreal = w->pr;
			w->nimg = w->pi;
			w->oreal = 0;
			w->oimg = 0;
			w->i = 0;
			calcbsh(w);
			w->color = color(w);
			mlx_pixel_wput(w, w->x, w->y);
			w->y++;
		}
		w->x++;
	}
}

void			calcmb2(t_env *w)
{
	while (w->i < w->end)
	{
		w->oreal = w->nreal;
		w->oimg = w->nimg;
		w->nreal = (w->oreal * w->oreal * w->oreal) -
		3 * w->oreal * w->oimg * w->oimg + w->pr;
		w->nimg = -(w->oimg * w->oimg * w->oimg) +
		3 * w->oreal * w->oreal * w->oimg + w->pi;
		if ((w->nreal * w->nreal + w->nimg * w->nimg) > 4)
			break ;
		w->i++;
	}
}

void			draw_multbrot2(t_env *w)
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
			calcmb2(w);
			w->color = color(w);
			mlx_pixel_wput(w, w->x, w->y);
			w->y++;
		}
		w->x++;
	}
}
