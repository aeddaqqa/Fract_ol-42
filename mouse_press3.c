/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 22:10:19 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/29 22:43:21 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_up_multi(t_multi *f)
{
	f->minre = f->mouse_r + ((f->minre - f->mouse_r) * 0.80);
	f->maxre = f->mouse_r + ((f->maxre - f->mouse_r) * 0.80);
	f->minim = f->mouse_i + ((f->minim - f->mouse_i) * 0.80);
	f->maxim = f->mouse_i + ((f->maxim - f->mouse_i) * 0.80);
}

void	zoom_dw_multi(t_multi *f)
{
	f->minre = f->mouse_r + ((f->minre - f->mouse_r) * 1.20);
	f->maxre = f->mouse_r + ((f->maxre - f->mouse_r) * 1.20);
	f->minim = f->mouse_i + ((f->minim - f->mouse_i) * 1.20);
	f->maxim = f->mouse_i + ((f->maxim - f->mouse_i) * 1.20);
}

void	zoom_up_fe(t_feig *f)
{
	f->minre = f->mouse_r + ((f->minre - f->mouse_r) * 0.80);
	f->maxre = f->mouse_r + ((f->maxre - f->mouse_r) * 0.80);
	f->minim = f->mouse_i + ((f->minim - f->mouse_i) * 0.80);
	f->maxim = f->mouse_i + ((f->maxim - f->mouse_i) * 0.80);
}

void	zoom_dw_fe(t_feig *f)
{
	f->minre = f->mouse_r + ((f->minre - f->mouse_r) * 1.20);
	f->maxre = f->mouse_r + ((f->maxre - f->mouse_r) * 1.20);
	f->minim = f->mouse_i + ((f->minim - f->mouse_i) * 1.20);
	f->maxim = f->mouse_i + ((f->maxim - f->mouse_i) * 1.20);
}
