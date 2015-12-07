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

void		setcursor(t_env *w)
{
	if (w->curs == 1)
	{
		SDL_ShowCursor(SDL_ENABLE);
		w->curs = 0;
		SDL_Delay(100);
	}
	else
	{
		SDL_ShowCursor(SDL_DISABLE);
		w->curs = 1;
		SDL_Delay(100);
	}
}

void		exit_game(t_env *w)
{
	free(w);
	SDL_Quit();
	exit(1);
}

void		dance(t_env *w)
{
	while (1)
	{
		while (SDL_PollEvent(&w->event))
		{
			if (w->event.type == SDL_KEYDOWN)
				if (w->event.key.keysym.sym == 27)
					exit_game(w);
			if (w->event.type == SDL_MOUSEMOTION)
				motion_events(w);
			if (w->event.type == SDL_MOUSEWHEEL)
				wheel_events(w);
		}
		chdraw(w);
		SDL_UpdateTexture(w->txtr, NULL, w->pix, (WIDTH) * sizeof(Uint32));
		SDL_RenderCopy(w->rdr, w->txtr, NULL, NULL);
		SDL_RenderPresent(w->rdr);
		w->inkeys = SDL_GetKeyboardState(NULL);
		key_events(w);
		SDL_Delay(8);
	}
}
