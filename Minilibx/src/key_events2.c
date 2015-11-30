/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:56:08 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:56:09 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void		ft_2(t_env *w)
{
	if (w->mode == 1)
		w->color_mod = 2;
	if (w->mode == 2)
	{
		if (w->fractal_mod != 2)
		{
			w->fractal_mod = 2;
			usleep(100000);
		}
		else
		{
			w->fractal_mod = 1;
			usleep(100000);
		}
	}
	if (w->mode == 3)
		w->fractal = 2;
}

void		ft_3(t_env *w)
{
	if (w->mode == 1)
		w->color_mod = 3;
	if (w->mode == 2)
	{
		if (w->fractal_mod == 1 || w->fractal_mod == 2)
		{
			w->fractal_mod = 3;
			usleep(100000);
		}
		else
		{
			w->fractal_mod = 1;
			usleep(100000);
		}
	}
	if (w->mode == 3)
		w->fractal = 3;
}

void		ft_4(t_env *w)
{
	if (w->mode == 1)
		w->color_mod = 4;
	if (w->mode == 3)
		w->fractal = 4;
}

void		ft_5(t_env *w)
{
	if (w->mode == 1)
		w->color_mod = 5;
	if (w->mode == 3)
		w->fractal = 5;
}

void		ft_6(t_env *w)
{
	if (w->mode == 1)
		w->color_mod = 6;
}
