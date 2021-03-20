/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:46:16 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/29 22:37:47 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	trans_d(t_mandl *f, int keycode)
{
	double alpha;
	double beta;

	alpha = (f->maxre - f->minre) * 0.05;
	beta = (f->maxim - f->minim) * 0.05;
	if (keycode == 124)
	{
		f->minre = f->minre - alpha;
		f->maxre = f->maxre - alpha;
	}
	else if (keycode == 123)
	{
		f->minre = f->minre + alpha;
		f->maxre = f->maxre + alpha;
	}
	else if (keycode == 125)
	{
		f->minim = f->minim - beta;
		f->maxim = f->maxim - beta;
	}
	else
	{
		f->minim = f->minim + beta;
		f->maxim = f->maxim + beta;
	}
}

void	trans_j(t_julia *f, int keycode)
{
	double alpha;
	double beta;

	alpha = (f->maxre - f->minre) * 0.05;
	beta = (f->maxim - f->minim) * 0.05;
	if (keycode == 125)
	{
		f->minre = f->minre - alpha;
		f->maxre = f->maxre - alpha;
	}
	else if (keycode == 126)
	{
		f->minre = f->minre + alpha;
		f->maxre = f->maxre + alpha;
	}
	else if (keycode == 124)
	{
		f->minim = f->minim - beta;
		f->maxim = f->maxim - beta;
	}
	else
	{
		f->minim = f->minim + beta;
		f->maxim = f->maxim + beta;
	}
}

void	trans_mu(t_multi *f, int keycode)
{
	double alpha;
	double beta;

	alpha = (f->maxre - f->minre) * 0.05;
	beta = (f->maxim - f->minim) * 0.05;
	if (keycode == 124)
	{
		f->minre = f->minre - alpha;
		f->maxre = f->maxre - alpha;
	}
	else if (keycode == 123)
	{
		f->minre = f->minre + alpha;
		f->maxre = f->maxre + alpha;
	}
	else if (keycode == 125)
	{
		f->minim = f->minim - beta;
		f->maxim = f->maxim - beta;
	}
	else
	{
		f->minim = f->minim + beta;
		f->maxim = f->maxim + beta;
	}
}

void	trans_fe(t_feig *f, int keycode)
{
	double alpha;
	double beta;

	alpha = (f->maxre - f->minre) * 0.05;
	beta = (f->maxim - f->minim) * 0.05;
	if (keycode == 124)
	{
		f->minre = f->minre - alpha;
		f->maxre = f->maxre - alpha;
	}
	else if (keycode == 123)
	{
		f->minre = f->minre + alpha;
		f->maxre = f->maxre + alpha;
	}
	else if (keycode == 125)
	{
		f->minim = f->minim - beta;
		f->maxim = f->maxim - beta;
	}
	else
	{
		f->minim = f->minim + beta;
		f->maxim = f->maxim + beta;
	}
}

void	change_color_fe(t_feig *f)
{
	if (f->ind_c == 4)
		f->ind_c = 0;
	else
		f->ind_c += 1;
}
