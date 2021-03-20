/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 16:48:11 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/28 17:05:41 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlbt(t_mandl *f)
{
	f->minre = -2.1;
	f->maxre = 0.6;
	f->minim = -1.2;
	f->maxim = 1.2;
	f->iter_max = 150;
}

void	init_multi(t_multi *f)
{
	f->minre = -1.5;
	f->maxre = 1.5;
	f->minim = -1.5;
	f->maxim = 1.5;
	f->iter_max = 100;
}

void	init_feig(t_feig *f)
{
	f->minre = -1.5;
	f->maxre = 1.5;
	f->minim = -1.5;
	f->maxim = 1.5;
	f->iter_max = 500;
}

void	init(t_fract *l)
{
	init_color_mand(&l->f);
	init_mlbt(&l->f);
	init_color_ju(&l->j);
	init_julia(&l->j);
	init_color_mu(&l->m);
	init_multi(&l->m);
	init_color_fe(&l->q);
	init_feig(&l->q);
}

void	init_julia(t_julia *j)
{
	j->minre = -1.50;
	j->maxre = 1.50;
	j->minim = -1.5;
	j->maxim = 1.5;
	j->iter_max = 200;
	j->c.r = 0.285;
	j->c.i = 0.013;
	j->stop = 1;
}
