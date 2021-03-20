/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:51:35 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/28 17:05:02 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	*part1_j(void *arg)
{
	t_julia	*f;
	int		i;
	int		j;
	int		iter;
	t_cmp	z;

	f = (t_julia *)arg;
	i = -1;
	while (++i < S / 2)
	{
		j = 0;
		while (j < S / 2)
		{
			z.i = i / f->image_x + f->minre;
			z.r = j / f->image_y + f->minim;
			iter = jjj(f, f->c, z);
			if (iter < f->iter_max)
				f->data[i * S + j] = get_color(f->iter_max, iter,
						f->color[f->ind_c], f->m);
			else
				f->data[i * S + j] = 0;
			j++;
		}
	}
	return (NULL);
}

static void	*part2_j(void *arg)
{
	t_julia	*f;
	int		i;
	int		j;
	int		iter;
	t_cmp	z;

	f = (t_julia *)arg;
	i = -1;
	while (++i < S / 2)
	{
		j = S / 2;
		while (j < S)
		{
			z.i = i / f->image_x + f->minre;
			z.r = j / f->image_y + f->minim;
			iter = jjj(f, f->c, z);
			if (iter < f->iter_max)
				f->data[i * S + j] = get_color(f->iter_max,
						iter, f->color[f->ind_c], f->m);
			else
				f->data[i * S + j] = 0;
			j++;
		}
	}
	return (NULL);
}

static void	*part3_j(void *arg)
{
	t_julia *f;
	int		i;
	int		j;
	int		iter;
	t_cmp	z;

	f = (t_julia *)arg;
	i = S / 2;
	while (i < S)
	{
		j = -1;
		while (++j < S / 2)
		{
			z.i = i / f->image_x + f->minre;
			z.r = j / f->image_y + f->minim;
			iter = jjj(f, f->c, z);
			if (iter < f->iter_max)
				f->data[i * S + j] = get_color(f->iter_max,
						iter, f->color[f->ind_c], f->m);
			else
				f->data[i * S + j] = 0;
		}
		i++;
	}
	return (NULL);
}

static void	*part4_j(void *arg)
{
	t_julia	*f;
	int		i;
	int		j;
	int		iter;
	t_cmp	z;

	f = (t_julia *)arg;
	i = S / 2 - 1;
	while (++i < S)
	{
		j = S / 2;
		while (j < S)
		{
			z.i = i / f->image_x + f->minre;
			z.r = j / f->image_y + f->minim;
			iter = jjj(f, f->c, z);
			if (iter < f->iter_max)
				f->data[i * S + j] = get_color(f->iter_max,
						iter, f->color[f->ind_c], f->m);
			else
				f->data[i * S + j] = 0;
			j++;
		}
	}
	return (NULL);
}

void		draw_jul(t_fract *l)
{
	int		i;
	t_julia	*f;

	f = &l->j;
	f->data = (int*)mlx_get_data_addr(l->img_ptr, &l->a, &l->b, &l->c);
	f->image_x = S / (f->maxre - f->minre);
	f->image_y = S / (f->maxim - f->minim);
	pthread_create(&f->trd[0], NULL, part1_j, (void *)f);
	pthread_create(&f->trd[1], NULL, part2_j, (void *)f);
	pthread_create(&f->trd[2], NULL, part3_j, (void *)f);
	pthread_create(&f->trd[3], NULL, part4_j, (void *)f);
	i = -1;
	while (++i < 4)
		pthread_join(f->trd[i], NULL);
	mlx_put_image_to_window(l->mlx_ptr, l->win_ptr, l->img_ptr, 0, 0);
}
