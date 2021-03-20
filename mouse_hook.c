/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:44:23 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/29 22:39:52 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_ju_up(t_julia *f)
{
	f->minre = f->mouse_r + ((f->minre - f->mouse_r) * 0.80);
	f->maxre = f->mouse_r + ((f->maxre - f->mouse_r) * 0.80);
	f->minim = f->mouse_i + ((f->minim - f->mouse_i) * 0.80);
	f->maxim = f->mouse_i + ((f->maxim - f->mouse_i) * 0.80);
}

void	zoom_ju_dw(t_julia *f)
{
	f->minre = f->mouse_r + ((f->minre - f->mouse_r) * 1.20);
	f->maxre = f->mouse_r + ((f->maxre - f->mouse_r) * 1.20);
	f->minim = f->mouse_i + ((f->minim - f->mouse_i) * 1.20);
	f->maxim = f->mouse_i + ((f->maxim - f->mouse_i) * 1.20);
}

void	zoom_up_mand(t_mandl *f)
{
	f->minre = f->mouse_r + ((f->minre - f->mouse_r) * 0.80);
	f->maxre = f->mouse_r + ((f->maxre - f->mouse_r) * 0.80);
	f->minim = f->mouse_i + ((f->minim - f->mouse_i) * 0.80);
	f->maxim = f->mouse_i + ((f->maxim - f->mouse_i) * 0.80);
}

void	zoom_dw_mand(t_mandl *f)
{
	f->minre = f->mouse_r + ((f->minre - f->mouse_r) * 1.20);
	f->maxre = f->mouse_r + ((f->maxre - f->mouse_r) * 1.20);
	f->minim = f->mouse_i + ((f->minim - f->mouse_i) * 1.20);
	f->maxim = f->mouse_i + ((f->maxim - f->mouse_i) * 1.20);
}
