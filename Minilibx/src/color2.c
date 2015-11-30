/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:55:12 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:55:16 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

unsigned long						cmod6(t_env *w)
{
	static int				a;
	static int				ro;
	static int				g;
	static int				b;
	double					mu;

	if (w->end > 0)
		mu = (w->i + 1) / w->end - log(log(w->nreal * w->nreal
			+ w->nimg * w->nimg) / log(2));
	else
		mu = (w->i + 1) / (w->end + 1) - log(log(w->nreal * w->nreal
			+ w->nimg * w->nimg) / log(2));
	a = 255;
	ro = w->i + ro + mu;
	g = w->i + g + mu;
	b = w->i + b + mu;
	return ((((((a << 8) + ro) << 8) + g) << 8) + b);
}

unsigned long						cmod5(t_env *w)
{
	static int				a;
	static int				ro;
	static int				g;
	static int				b;
	double					mu;

	if (w->end > 0)
		mu = w->i + 1 - log(log(w->oreal * w->oreal
			+ w->oimg * w->oimg) / log(2));
	else
		mu = w->i - log(log(w->nreal * w->nreal
			+ w->nimg * w->nimg) / log(2));
	a = 255;
	ro = 10 + mu;
	g = 100 + mu;
	b = 1;
	return ((((((a << 8) + ro) << 8) + g) << 8) + b);
}

unsigned long						cmod4(t_env *w)
{
	int						a;
	int						ro;
	int						g;
	int						b;
	double					mu;

	mu = (w->i + 1) - log(log(w->oreal * w->oreal
		+ w->oimg * w->oimg) / log(2));
	a = 255;
	ro = 255 * mu / w->i;
	g = 255 * mu;
	b = 255 / mu;
	return ((((((a << 8) + ro) << 8) + g) << 8) + b);
}
