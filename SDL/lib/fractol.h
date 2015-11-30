/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 10:04:25 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 10:04:26 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "SDL2.framework/Headers/SDL.h"
# include "libft/inc/libft.h"
# define WIDTH		600
# define HEIGHT		600
# define NAME		"fract'ol"
# define KEY		w->event.key.keysym.sym
# define WHEEL		w->event.wheel
# define MOUSE		w->event.motion

typedef struct		s_env
{
	SDL_Texture		*txtr;
	SDL_Window		*win;
	SDL_Renderer	*rdr;
	SDL_Event		event;
	const Uint8		*inkeys;
	Uint32			color;
	int				endian;
	int				bpp;
	Uint32			*pix;
	int				s_line;
	double			zoom;
	double			posx;
	double			posy;
	int				end;
	double			crealp;
	double			oreal;
	double			nreal;
	double			cimg;
	double			oimg;
	double			nimg;
	double			pr;
	double			pi;
	int				x;
	int				y;
	int				i;
	double			xsouris;
	double			ysouris;
	int				mode;
	int				curs;
	int				fractal_mod;
	int				color_mod;
	int				fractal;
}					t_env;

int					init_sdl(t_env *w);
void				init_fractal(t_env *w, char **av);
void				init_vals(t_env *w);
void				chdraw(t_env *w);
void				draw(t_env *w);
void				draw_mdb(t_env *w);
void				mlx_pixel_wput(t_env *w, int x, int y);
void				dance(t_env *w);
void				exit_game(t_env *w);
void				setcursor(t_env *w);
void				zoomin(t_env *w);
void				zoomout(t_env *w);
void				iteration_less(t_env *w);
void				iteration_more(t_env *w);
void				key_events(t_env *w);
void				choose_mode(t_env *w);
void				move(t_env *w);
void				shape(t_env *w);
void				motion_events(t_env *w);
void				wheel_events(t_env *w);
void				mv_up(t_env *w);
void				mv_down(t_env *w);
void				mv_left(t_env *w);
void				mv_right(t_env *w);
void				shape_r_pos(t_env *w);
void				shape_r_neg(t_env *w);
void				shape_i_neg(t_env *w);
void				shape_i_pos(t_env *w);
Uint32				cmod6(t_env *w);
Uint32				cmod5(t_env *w);
Uint32				cmod4(t_env *w);
Uint32				cmod3(t_env *w);
Uint32				cmod2(t_env *w);
Uint32				cmod1(t_env *w);
Uint32				color(t_env *w);
void				ft_1(t_env *w);
void				ft_2(t_env *w);
void				ft_3(t_env *w);
void				ft_4(t_env *w);
void				ft_5(t_env *w);
void				ft_6(t_env *w);
void				draw(t_env *w);
void				draw_mdb(t_env *w);
void				draw_bsh(t_env *w);
void				draw_multbrot2(t_env *w);
void				draw_multbrot3(t_env *w);
void				init_color(t_env *w, char **av);

#endif
