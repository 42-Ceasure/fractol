/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:56:54 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:56:55 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void		mv_up(t_env *w)
{
	w->posy = w->posy + 0.01 / w->zoom;
}

void		mv_down(t_env *w)
{
	w->posy = w->posy - 0.01 / w->zoom;
}

void		mv_left(t_env *w)
{
	w->posx = w->posx + 0.01 / w->zoom;
}

void		mv_right(t_env *w)
{
	w->posx = w->posx - 0.01 / w->zoom;
}
