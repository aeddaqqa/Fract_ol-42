/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:47:12 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/30 14:32:54 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include <pthread.h>
# include <math.h>
# include <unistd.h>

# define S 800

typedef struct	s_rgb
{
	int r;
	int g;
	int b;
}				t_rgb;

typedef	struct	s_vect
{
	int		a;
	int		b;
	int		z;
}				t_vect;

typedef	struct	s_point
{
	int		x;
	int		y;
	int		color;
}				t_point;

typedef struct	s_mandl
{
	int			iter_max;
	int			m;
	int			ind_c;
	double		maxre;
	double		minre;
	double		maxim;
	double		minim;
	double		image_x;
	double		image_y;
	double		mouse_r;
	double		mouse_i;
	pthread_t	trd[4];
	t_rgb		color[5];
	int			*data;
}				t_mandl;

typedef struct	s_cmp
{
	double r;
	double i;
}				t_cmp;

typedef struct	s_julia
{
	int			iter_max;
	int			ind_c;
	int			m;
	int			stop;
	double		maxre;
	double		minre;
	double		maxim;
	double		minim;
	double		image_x;
	double		image_y;
	double		mouse_r;
	double		mouse_i;
	int			*data;
	t_cmp		c;
	pthread_t	trd[4];
	t_rgb		color[5];
}				t_julia;

typedef struct	s_multi
{
	int			iter_max;
	int			m;
	int			ind_c;
	double		maxre;
	double		minre;
	double		maxim;
	double		minim;
	double		image_x;
	double		image_y;
	double		mouse_r;
	double		mouse_i;
	int			*data;
	pthread_t	trd[4];
	t_rgb		color[5];
}				t_multi;

typedef struct	s_feig
{
	int			iter_max;
	int			m;
	int			ind_c;
	double		maxre;
	double		minre;
	double		maxim;
	double		minim;
	double		image_x;
	double		image_y;
	double		mouse_r;
	double		mouse_i;
	int			*data;
	pthread_t	trd[4];
	t_rgb		color[5];
}				t_feig;

typedef struct	s_fract
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			a;
	int			b;
	int			c;
	int			var;
	t_mandl		f;
	t_julia		j;
	t_multi		m;
	t_feig		q;
}				t_fract;

void			draw_feigen(t_fract *f);
void			init_color_fe(t_feig *f);
int				sss(t_feig *f, t_cmp c);
int				key_press_fe(int keycode, t_feig *f);
int				mouse_press_fe(int button, int x, int y, t_feig *f);
int				mouse_move(int x, int y, t_fract *f);
void			zoom_up_mand(t_mandl *f);
void			zoom_dw_mand(t_mandl *f);
int				jjj(t_julia *f, t_cmp c, t_cmp z);
int				ppp(t_mandl *f, t_cmp c);
int				get_color(int l, int nb, t_rgb c, int m);
void			init_julia(t_julia *j);
void			draw_mand(t_fract *f);
void			draw_jul(t_fract *f);
int				mouse_press_ju(int button, int x, int y, t_julia *f);
int				key_press_ju(int keycode, t_julia *f);
int				mouse_press_mand(int button, int x, int y, t_mandl *f);
int				key_press_mand(int keycode, t_mandl *f);
void			init_color_mand(t_mandl *f);
void			init_color_ju(t_julia *f);
void			draw_multi(t_fract *f);
void			init_color_mu(t_multi *f);
int				key_press_multi(int keycode, t_multi *f);
int				mmm(t_multi *f, t_cmp c);
int				mouse_press_multi(int button, int x, int y, t_multi *f);
void			draw(t_fract *f);
void			init_mlbt(t_mandl *f);
void			init_multi(t_multi *f);
void			init_feig(t_feig *f);
void			init_julia(t_julia *j);
int				key_press(int keycode, t_fract *l);
int				mouse_press(int button, int x, int y, t_fract *l);
void			init(t_fract *l);
void			menu(t_fract l);
void			iter_plus_m(int keycode, t_fract *l);
void			init_fract(t_fract *l);
void			change_fract(int keycode, t_fract *l);
void			change_color(t_fract *l, int v);
void			change_color_multi(t_multi *f);
void			change_multi(t_multi *f);
void			change_color_fe(t_feig *f);
void			change_fe(t_feig *f);
void			change_color_m(t_mandl *f);
void			change_m(t_mandl *f);
void			change_color_j(t_julia *f);
void			change_j(t_julia *f);
void			trans_fe(t_feig *f, int keycode);
void			trans_mu(t_multi *f, int keycode);
void			trans_j(t_julia *f, int keycode);
void			trans_d(t_mandl *f, int keycode);
void			zoom_dw_fe(t_feig *f);
void			zoom_up_fe(t_feig *f);
void			zoom_dw_multi(t_multi *f);
void			zoom_up_multi(t_multi *f);
void			zoom_ju_dw(t_julia *f);
void			zoom_ju_up(t_julia *f);
void			gestion_error(void);
void			ft_putstr(char *str);
void			part2_iter(int keycode, t_fract *l);
#endif
