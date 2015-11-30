/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractales3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 09:57:41 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 09:57:41 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void			calcj(t_env *w)
{
	while (w->i < w->end)
	{
		w->oreal = w->nreal;
		w->oimg = w->nimg;
		w->nreal = w->oreal * w->oreal - w->oimg * w->oimg + w->crealp;
		w->nimg = 2 * w->oreal * w->oimg + w->cimg;
		if ((w->nreal * w->nreal + w->nimg * w->nimg) > 4)
			break ;
		w->i++;
	}
}

void			draw(t_env *w)
{
	w->x = 0;
	while (w->x < WIDTH)
	{
		w->y = 0;
		while (w->y < HEIGHT)
		{
			w->nreal = 1 * (w->x - WIDTH / 2) /
			(0.5 * w->zoom * WIDTH) + w->posx;
			w->nimg = (w->y - HEIGHT / 2) / (0.5 * w->zoom * HEIGHT) + w->posy;
			w->i = 0;
			calcj(w);
			w->color = color(w);
			mlx_pixel_wput(w, w->x, w->y);
			w->y++;
		}
		w->x++;
	}
}
