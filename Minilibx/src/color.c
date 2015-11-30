/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:54:57 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:54:59 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void				mlx_pixel_wput(t_env *w, int x, int y)
{
	unsigned int	place;
	int				r;
	int				g;
	int				b;

	place = y * ((WIDTH) * 4);
	place += x * 4;
	r = (w->color & 0xFF0000) >> 16;
	g = (w->color & 0xFF00) >> 8;
	b = (w->color & 0xFF);
	if (x > 0 && x < WIDTH)
	{
		place = y * ((WIDTH) * 4);
		place += x * 4;
		if (place < (((WIDTH) * (HEIGHT)) * (sizeof(char) * 4)))
		{
			w->data[place] = b;
			w->data[place + 1] = g;
			w->data[place + 2] = r;
		}
	}
}

unsigned long		cmod3(t_env *w)
{
	int				a;
	int				ro;
	int				g;
	int				b;
	double			mu;

	mu = (w->i + 1) - log(log(w->x * w->x + w->y * w->y) / log(2));
	a = 255;
	ro = 255 * mu / w->i;
	g = 255 * mu;
	b = 255 / mu;
	return ((((((a << 8) + ro) << 8) + g) << 8) + b);
}

unsigned long		cmod2(t_env *w)
{
	int				a;
	int				ro;
	int				g;
	int				b;

	a = 255;
	g = w->i % 256;
	b = 255 * cos(w->i);
	if (w->i < w->end)
	{
		if (w->end > 0)
			ro = 255 * sin(w->i) / w->end;
		else
			ro = 255 * sin(w->i);
	}
	else
		ro = 0;
	return ((((((a << 8) + ro) << 8) + g) << 8) + b);
}

unsigned long		cmod1(t_env *w)
{
	int				a;
	int				ro;
	int				g;
	int				b;

	a = 255;
	ro = 0;
	b = 0;
	if (w->end > 0)
		g = w->i * 255 / w->end;
	else
		g = w->i * 255 / (w->end + 1);
	return ((((((a << 8) + ro) << 8) + g) << 8) + b);
}

unsigned long		color(t_env *w)
{
	if (w->color_mod == 1)
		return (cmod1(w));
	else if (w->color_mod == 2)
		return (cmod2(w));
	else if (w->color_mod == 3)
		return (cmod3(w));
	else if (w->color_mod == 4)
		return (cmod4(w));
	else if (w->color_mod == 5)
		return (cmod5(w));
	else if (w->color_mod == 6)
		return (cmod6(w));
	else
		return (0);
}
