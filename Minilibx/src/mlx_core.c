/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 05:56:28 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 05:56:29 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/fractol.h"

void		exit_game(t_env *w)
{
	free(w);
	exit(1);
}

int			expose_hook(t_env *w)
{
	chdraw(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img, 0, 0);
	return (0);
}
