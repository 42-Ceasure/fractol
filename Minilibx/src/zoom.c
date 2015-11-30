/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:57:15 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:57:16 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void		zoomin(t_env *w)
{
	w->posx = w->posx - w->xsouris;
	w->posy = w->posy - w->ysouris;
	w->zoom = w->zoom * 1.1;
	w->posx = w->posx + (w->xsouris * (w->zoom / 1.1) / w->zoom);
	w->posy = w->posy + (w->ysouris * (w->zoom / 1.1) / w->zoom);
}

void		zoomout(t_env *w)
{
	w->posx = w->posx - w->xsouris;
	w->posy = w->posy - w->ysouris;
	w->zoom = w->zoom / 1.1;
	w->posx = w->posx + (w->xsouris * (w->zoom * 1.1) / w->zoom);
	w->posy = w->posy + (w->ysouris * (w->zoom * 1.1) / w->zoom);
}

void		iteration_less(t_env *w)
{
	if (w->end > 5)
		w->end = w->end - 5;
	else if (w->end <= 5 && w->end > 0)
		w->end = w->end - 1;
}

void		iteration_more(t_env *w)
{
	w->end = w->end + 5;
}
