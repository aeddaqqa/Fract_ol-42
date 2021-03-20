/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:58:06 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/29 22:37:38 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	change_j(t_julia *f)
{
	if (f->m == 2)
		f->m = 0;
	else
		f->m += 1;
}

void	change_color_j(t_julia *f)
{
	if (f->ind_c == 4)
		f->ind_c = 0;
	else
		f->ind_c += 1;
}

void	change_m(t_mandl *f)
{
	if (f->m == 2)
		f->m = 0;
	else
		f->m += 1;
}

void	change_color_m(t_mandl *f)
{
	if (f->ind_c == 4)
		f->ind_c = 0;
	else
		f->ind_c += 1;
}

void	change_fe(t_feig *f)
{
	if (f->m == 2)
		f->m = 0;
	else
		f->m += 1;
}
