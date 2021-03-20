/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:10:18 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/29 12:16:49 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*part1(void *arg)
{
	t_mandl	*f;
	int		i;
	int		j;
	int		z;
	t_cmp	c;

	f = (t_mandl *)arg;
	i = -1;
	while (++i < S / 2)
	{
		j = 0;
		while (j < S / 2)
		{
			c.r = j / f->image_x + f->minre;
			c.i = i / f->image_y + f->minim;
			z = ppp(f, c);
			if (z < f->iter_max)
				f->data[i * S + j] = get_color(f->iter_max,
						z, f->color[f->ind_c], f->m);
			else
				f->data[i * S + j] = 0;
			j++;
		}
	}
	return (NULL);
}

static void	*part2(void *arg)
{
	t_mandl	*f;
	int		i;
	int		j;
	int		z;
	t_cmp	c;

	f = (t_mandl *)arg;
	i = -1;
	while (++i < S / 2)
	{
		j = S / 2;
		while (j < S)
		{
			c.r = j / f->image_x + f->minre;
			c.i = i / f->image_y + f->minim;
			z = ppp(f, c);
			if (z < f->iter_max)
				f->data[i * S + j] = get_color(f->iter_max, z,
						f->color[f->ind_c], f->m);
			else
				f->data[i * S + j] = 0;
			j++;
		}
	}
	return (NULL);
}

static void	*part3(void *arg)
{
	t_mandl	*f;
	int		i;
	int		j;
	int		z;
	t_cmp	c;

	f = (t_mandl *)arg;
	i = S / 2;
	while (i < S)
	{
		j = -1;
		while (++j < S / 2)
		{
			c.r = j / f->image_x + f->minre;
			c.i = i / f->image_y + f->minim;
			z = ppp(f, c);
			if (z < f->iter_max)
				f->data[i * S + j] = get_color(f->iter_max, z,
						f->color[f->ind_c], f->m);
			else
				f->data[i * S + j] = 0;
		}
		i++;
	}
	return (NULL);
}

static void	*part4(void *arg)
{
	t_mandl	*f;
	int		i;
	int		j;
	int		z;
	t_cmp	c;

	f = (t_mandl *)arg;
	i = S / 2 - 1;
	while (++i < S)
	{
		j = S / 2;
		while (j < S)
		{
			c.r = j / f->image_x + f->minre;
			c.i = i / f->image_y + f->minim;
			z = ppp(f, c);
			if (z < f->iter_max)
				f->data[i * S + j] = get_color(f->iter_max, z,
						f->color[f->ind_c], f->m);
			else
				f->data[i * S + j] = 0;
			j++;
		}
	}
	return (NULL);
}

void		draw_mand(t_fract *l)
{
	int		i;
	t_mandl	*f;

	f = &l->f;
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
