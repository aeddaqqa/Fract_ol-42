/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 02:51:40 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/28 17:50:50 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	bsbs(t_rgb *t)
{
	t[0].r = 255;
	t[0].g = t[0].r * 0.5;
	t[0].b = t[0].r * 255 + t[0].g * 255;
	t[1].r = 255;
	t[1].g = 255;
	t[1].b = 255;
	t[2].r = 130;
	t[2].g = 250;
	t[2].b = 9;
	t[3].r = 205;
	t[3].g = 250;
	t[3].b = 250;
	t[4].r = 120;
	t[4].g = 5;
	t[4].b = 255;
}

void	init_color_mand(t_mandl *f)
{
	f->ind_c = 0;
	f->m = 0;
	bsbs(f->color);
}

void	init_color_ju(t_julia *f)
{
	f->ind_c = 0;
	f->m = 0;
	bsbs(f->color);
}

void	init_color_mu(t_multi *f)
{
	f->ind_c = 0;
	f->m = 0;
	bsbs(f->color);
}

void	init_color_fe(t_feig *f)
{
	f->ind_c = 0;
	f->m = 0;
	bsbs(f->color);
}
