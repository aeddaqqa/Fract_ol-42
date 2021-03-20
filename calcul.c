/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:23:11 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/30 14:24:55 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int l, int nb, t_rgb c, int m)
{
	int		blue;
	int		red;
	int		green;
	double	v;

	v = (double)nb / (double)l;
	blue = 0;
	red = 0;
	green = 0;
	if (m == 1)
	{
		blue = (8.5 * (1 - v) * (1 - v) * (1 - v) * v * c.b);
		green = (15 * (1 - v) * (1 - v) * v * v * c.g);
		red = (9 * (1 - v) * v * v * v * c.r);
	}
	else if (m == 0)
		return ((0xffffff + (nb * 5000)));
	else if (m == 2)
	{
		blue = nb * c.b / 50;
		green = nb * c.g / 50;
		red = nb * c.r / 50;
	}
	return ((red << 16 | green << 8 | blue));
}

int		ppp(t_mandl *f, t_cmp c)
{
	int		z;
	double	tmp;
	double	z_r;
	double	z_i;

	z_r = 0;
	z_i = 0;
	z = 0;
	while (z_r * z_r + z_i * z_i < 4 && z < f->iter_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c.r;
		z_i = 2 * z_i * tmp + c.i;
		z++;
	}
	return (z);
}

int		mmm(t_multi *f, t_cmp c)
{
	int		z;
	double	tmp;
	double	z_r;
	double	z_i;

	z_r = 0;
	z_i = 0;
	z = 0;
	while (z_r * z_r + z_i * z_i < 4 && z < f->iter_max)
	{
		tmp = z_r;
		z_r = z_r * z_r * z_r * z_r - 6
			* z_r * z_r * z_i * z_i + z_i * z_i * z_i * z_i + c.r;
		z_i = 4 * tmp * tmp * tmp * z_i - 4 * tmp * z_i * z_i * z_i + c.i;
		z++;
	}
	return (z);
}

int		jjj(t_julia *f, t_cmp c, t_cmp z)
{
	int		k;
	double	tmp;

	k = 0;
	while (z.r * z.r + z.i * z.i < 4 && k < f->iter_max)
	{
		tmp = z.r;
		z.r = z.r * z.r - z.i * z.i + c.r;
		z.i = 2 * z.i * tmp + c.i;
		k++;
	}
	return (k);
}

int		sss(t_feig *f, t_cmp c)
{
	int		z;
	double	tmp;
	double	z_r;
	double	z_i;

	z_r = 0;
	z_i = 0;
	z = 0;
	while (z_r * z_r + z_i * z_i < 4 && z < f->iter_max)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c.r - 1.401155;
		z_i = 2 * z_i * tmp + c.i;
		z++;
	}
	return (z);
}
