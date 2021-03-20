/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Feigenbaum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 04:04:39 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/29 12:34:32 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*part1(void *arg)
{
	t_feig	*f;
	t_vect	i;
	t_cmp	x;
	t_cmp	c;

	f = (t_feig *)arg;
	i.a = -1;
	while (++i.a < S / 2)
	{
		i.b = -1;
		while (++i.b < S / 2)
		{
			x.r = i.b / f->image_x + f->minre;
			x.i = i.a / f->image_y + f->minim;
			c.r = x.r * x.r * x.r - 3 * x.r * x.i * x.i;
			c.i = 3 * x.r * x.r * x.i - x.i * x.i * x.i;
			i.z = sss(f, c);
			if (i.z < f->iter_max)
				f->data[i.a * S + i.b] = get_color(f->iter_max, i.z,
						f->color[f->ind_c], f->m);
			else
				f->data[i.a * S + i.b] = 0;
		}
	}
	return (NULL);
}

static void	*part2(void *arg)
{
	t_feig	*f;
	t_vect	i;
	t_cmp	c;
	t_cmp	x;

	f = (t_feig *)arg;
	i.a = -1;
	while (++i.a < S / 2)
	{
		i.b = S / 2 - 1;
		while (++i.b < S)
		{
			x.r = i.b / f->image_x + f->minre;
			x.i = i.a / f->image_y + f->minim;
			c.r = x.r * x.r * x.r - 3 * x.r * x.i * x.i;
			c.i = 3 * x.r * x.r * x.i - x.i * x.i * x.i;
			i.z = sss(f, c);
			if (i.z < f->iter_max)
				f->data[i.a * S + i.b] = get_color(f->iter_max, i.z,
						f->color[f->ind_c], f->m);
			else
				f->data[i.a * S + i.b] = 0;
		}
	}
	return (NULL);
}

static void	*part3(void *arg)
{
	t_feig	*f;
	t_vect	i;
	t_cmp	c;
	t_cmp	x;

	f = (t_feig *)arg;
	i.a = S / 2 - 1;
	while (++i.a < S)
	{
		i.b = -1;
		while (++i.b < S / 2)
		{
			x.r = i.b / f->image_x + f->minre;
			x.i = i.a / f->image_y + f->minim;
			c.r = x.r * x.r * x.r - 3 * x.r * x.i * x.i;
			c.i = 3 * x.r * x.r * x.i - x.i * x.i * x.i;
			i.z = sss(f, c);
			if (i.z < f->iter_max)
				f->data[i.a * S + i.b] = get_color(f->iter_max, i.z,
						f->color[f->ind_c], f->m);
			else
				f->data[i.a * S + i.b] = 0;
		}
	}
	return (NULL);
}

static void	*part4(void *arg)
{
	t_feig	*f;
	t_vect	i;
	t_cmp	c;
	t_cmp	x;

	f = (t_feig *)arg;
	i.a = S / 2 - 1;
	while (++i.a < S)
	{
		i.b = S / 2 - 1;
		while (++i.b < S)
		{
			x.r = i.b / f->image_x + f->minre;
			x.i = i.a / f->image_y + f->minim;
			c.r = x.r * x.r * x.r - 3 * x.r * x.i * x.i;
			c.i = 3 * x.r * x.r * x.i - x.i * x.i * x.i;
			i.z = sss(f, c);
			if (i.z < f->iter_max)
				f->data[i.a * S + i.b] = get_color(f->iter_max, i.z,
						f->color[f->ind_c], f->m);
			else
				f->data[i.a * S + i.b] = 0;
		}
	}
	return (NULL);
}

void		draw_feigen(t_fract *l)
{
	int		i;
	t_feig	*f;

	f = &l->q;
	f->data = (int*)mlx_get_data_addr(l->img_ptr, &l->a, &l->b, &l->c);
	f->image_x = S / (f->maxre - f->minre);
	f->image_y = S / (f->maxim - f->minim);
	pthread_create(&f->trd[0], NULL, part1, (void *)f);
	pthread_create(&f->trd[1], NULL, part2, (void *)f);
	pthread_create(&f->trd[2], NULL, part3, (void *)f);
	pthread_create(&f->trd[3], NULL, part4, (void *)f);
	i = -1;
	while (++i < 4)
		pthread_join(f->trd[i], NULL);
	mlx_put_image_to_window(l->mlx_ptr, l->win_ptr, l->img_ptr, 0, 0);
}
