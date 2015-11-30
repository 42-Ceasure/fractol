/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:55:29 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:55:31 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void			chdraw(t_env *w)
{
	if (w->fractal == 1)
		draw(w);
	if (w->fractal == 2)
		draw_mdb(w);
	if (w->fractal == 3)
		draw_bsh(w);
	if (w->fractal == 4)
		draw_multbrot2(w);
	if (w->fractal == 5)
		draw_multbrot3(w);
}
