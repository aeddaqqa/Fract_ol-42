/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 21:42:44 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/29 22:37:48 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_press_fe(int keycode, t_feig *f)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 124 || keycode == 123 || keycode == 125 || keycode == 126)
		trans_fe(f, keycode);
	if (keycode == 8)
		change_fe(f);
	if (keycode == 9)
		change_color_fe(f);
	return (0);
}

int		key_press_multi(int keycode, t_multi *f)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 124 || keycode == 123 || keycode == 125 || keycode == 126)
		trans_mu(f, keycode);
	if (keycode == 8)
		change_multi(f);
	if (keycode == 9)
		change_color_multi(f);
	return (0);
}

int		key_press_mand(int keycode, t_mandl *f)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 124 || keycode == 123 || keycode == 125 || keycode == 126)
		trans_d(f, keycode);
	if (keycode == 8)
		change_m(f);
	if (keycode == 9)
		change_color_m(f);
	return (0);
}

int		key_press_ju(int keycode, t_julia *f)
{
	if (keycode == 53)
		exit(1);
	if (keycode == 49)
	{
		if (f->stop == 0)
			f->stop = 1;
		else
			f->stop = 0;
	}
	if (keycode == 124 || keycode == 123 || keycode == 125 || keycode == 126)
		trans_j(f, keycode);
	if (keycode == 8)
		change_j(f);
	if (keycode == 9)
		change_color_j(f);
	return (0);
}

void	change_color_multi(t_multi *f)
{
	if (f->ind_c == 4)
		f->ind_c = 0;
	else
		f->ind_c += 1;
}
