/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cglavieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 11:33:01 by cglavieu          #+#    #+#             */
/*   Updated: 2015/11/28 11:33:02 by cglavieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx_macos/mlx.h"
# include "libft/inc/libft.h"
# define WIDTH		600
# define HEIGHT		600
# define NAME		"fract'ol"
# define KEY		w->event.key.keysym.sym
# define WHEEL		w->event.wheel
# define MOUSE		w->event.motion

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned long	color;
	int				endian;
	int				bpp;
	char			*data;
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

int					init_mlx(t_env *w);
void				init_fractal(t_env *w, char **av);
void				init_vals(t_env *w);
void				chdraw(t_env *w);
void				draw(t_env *w);
void				draw_mdb(t_env *w);
void				mlx_pixel_wput(t_env *w, int x, int y);
int					expose_hook(t_env *w);
int					key_hook(int keycode, t_env *w);
void				dance(t_env *w);
void				exit_game(t_env *w);
void				zoomin(t_env *w);
void				zoomout(t_env *w);
void				iteration_less(t_env *w);
void				iteration_more(t_env *w);
void				choose_mode(int keycode, t_env *w);
void				move(int keycode, t_env *w);
void				shape(int keycode, t_env *w);
int					mouse_hook(int button, int x, int y, t_env *w);
int					motion_hook(int x, int y, t_env *w);
void				wheel_events(int button, t_env *w);
void				mv_up(t_env *w);
void				mv_down(t_env *w);
void				mv_left(t_env *w);
void				mv_right(t_env *w);
void				shape_r_pos(t_env *w);
void				shape_r_neg(t_env *w);
void				shape_i_neg(t_env *w);
void				shape_i_pos(t_env *w);
unsigned long		cmod6(t_env *w);
unsigned long		cmod5(t_env *w);
unsigned long		cmod4(t_env *w);
unsigned long		cmod3(t_env *w);
unsigned long		cmod2(t_env *w);
unsigned long		cmod1(t_env *w);
unsigned long		color(t_env *w);
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
