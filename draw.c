/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 02:53:04 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/29 22:52:46 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw(t_fract *l)
{
	l->img_ptr = mlx_new_image(l->mlx_ptr, S, S);
	if (l->var == 0)
		draw_mand(l);
	if (l->var == 1)
		draw_jul(l);
	if (l->var == 2)
		draw_multi(l);
	if (l->var == 3)
		draw_feigen(l);
}

void		change_fract(int keycode, t_fract *l)
{
	if (keycode == 13)
	{
		if (l->var == 3)
			l->var = 0;
		else
			l->var += 1;
	}
	else
	{
		if (l->var == 0)
			l->var = 3;
		else
			l->var -= 1;
	}
}

void		init_fract(t_fract *l)
{
	if (l->var == 0)
		init_mlbt(&l->f);
	if (l->var == 1)
		init_julia(&l->j);
	if (l->var == 2)
		init_multi(&l->m);
	if (l->var == 3)
		init_feig(&l->q);
}

void		iter_plus_m(int keycode, t_fract *l)
{
	if (l->var == 0)
	{
		if (keycode == 69)
			l->f.iter_max += 10;
		else if (keycode == 78 && l->f.iter_max > 50)
			l->f.iter_max -= 10;
	}
	else if (l->var == 1)
	{
		if (keycode == 69)
			l->j.iter_max += 10;
		else if (keycode == 78 && l->j.iter_max > 50)
			l->j.iter_max -= 10;
	}
	else
		part2_iter(keycode, l);
}

void		change_multi(t_multi *f)
{
	if (f->m == 2)
		f->m = 0;
	else
		f->m += 1;
}
