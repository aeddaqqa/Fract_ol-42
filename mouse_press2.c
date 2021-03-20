/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:01:46 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/29 22:42:38 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_press_fe(int button, int x, int y, t_feig *f)
{
	f->mouse_r = x / (S / (f->maxre - f->minre)) + f->minre;
	f->mouse_i = y / (S / (f->maxim - f->minim)) + f->minim;
	if (button == 5)
	{
		if (f->iter_max <= 1500)
			f->iter_max += 10;
		zoom_up_fe(f);
	}
	if (button == 4)
	{
		if (f->iter_max >= 50)
			f->iter_max -= 10;
		zoom_dw_fe(f);
	}
	return (0);
}

int		mouse_press_multi(int button, int x, int y, t_multi *f)
{
	f->mouse_r = x / (S / (f->maxre - f->minre)) + f->minre;
	f->mouse_i = y / (S / (f->maxim - f->minim)) + f->minim;
	if (button == 5)
	{
		if (f->iter_max <= 1500)
			f->iter_max += 10;
		zoom_up_multi(f);
	}
	if (button == 4)
	{
		if (f->iter_max >= 50)
			f->iter_max -= 10;
		zoom_dw_multi(f);
	}
	return (0);
}

int		mouse_press_mand(int button, int x, int y, t_mandl *f)
{
	f->mouse_r = x / (S / (f->maxre - f->minre)) + f->minre;
	f->mouse_i = y / (S / (f->maxim - f->minim)) + f->minim;
	if (button == 5)
	{
		if (f->iter_max <= 1500)
			f->iter_max += 10;
		zoom_up_mand(f);
	}
	if (button == 4)
	{
		if (f->iter_max >= 50)
			f->iter_max -= 10;
		zoom_dw_mand(f);
	}
	return (0);
}

int		mouse_press_ju(int button, int x, int y, t_julia *f)
{
	f->mouse_r = y / (S / (f->maxre - f->minre)) + f->minre;
	f->mouse_i = x / (S / (f->maxim - f->minim)) + f->minim;
	if (button == 5)
	{
		if (f->iter_max <= 1500)
			f->iter_max += 10;
		zoom_ju_up(f);
	}
	if (button == 4)
	{
		if (f->iter_max >= 50)
			f->iter_max -= 10;
		zoom_ju_dw(f);
	}
	return (0);
}

int		mouse_move(int x, int y, t_fract *l)
{
	t_julia *f;

	f = &l->j;
	if (f->stop == 0)
	{
		f->c.r = x / (S / (f->maxre - f->minre)) + f->minre;
		f->c.i = y / (S / (f->maxim - f->minim)) + f->minim;
		mlx_destroy_image(l->mlx_ptr, l->img_ptr);
		draw(l);
	}
	return (0);
}
