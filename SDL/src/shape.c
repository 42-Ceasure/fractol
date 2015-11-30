/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:57:06 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:57:06 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void		shape_r_pos(t_env *w)
{
	w->crealp = w->crealp + 0.002 / w->zoom;
}

void		shape_r_neg(t_env *w)
{
	w->crealp = w->crealp - 0.002 / w->zoom;
}

void		shape_i_neg(t_env *w)
{
	w->cimg = w->cimg + 0.002 / w->zoom;
}

void		shape_i_pos(t_env *w)
{
	w->cimg = w->cimg - 0.002 / w->zoom;
}
