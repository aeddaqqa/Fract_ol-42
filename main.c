/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 14:46:21 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/30 14:32:18 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int			mouse_press(int button, int x, int y, t_fract *l)
{
	mlx_destroy_image(l->mlx_ptr, l->img_ptr);
	if (l->var == 0)
		mouse_press_mand(button, x, y, &l->f);
	if (l->var == 1)
		mouse_press_ju(button, x, y, &l->j);
	if (l->var == 2)
		mouse_press_multi(button, x, y, &l->m);
	if (l->var == 3)
		mouse_press_fe(button, x, y, &l->q);
	draw(l);
	return (0);
}

int			key_press(int keycode, t_fract *l)
{
	mlx_destroy_image(l->mlx_ptr, l->img_ptr);
	if (keycode == 13 || keycode == 14)
		change_fract(keycode, l);
	if (keycode == 15)
		init_fract(l);
	if (keycode == 69 || keycode == 78)
		iter_plus_m(keycode, l);
	if (l->var == 0)
		key_press_mand(keycode, &l->f);
	if (l->var == 1)
		key_press_ju(keycode, &l->j);
	if (l->var == 2)
		key_press_multi(keycode, &l->m);
	if (l->var == 3)
		key_press_fe(keycode, &l->q);
	draw(l);
	return (0);
}

void		help1(t_fract *l, char **av)
{
	l->var = 5;
	if (!ft_strcmp(av[1], "Mandelbrot"))
		l->var = 0;
	if (!ft_strcmp(av[1], "Julia"))
		l->var = 1;
	if (!ft_strcmp(av[1], "Multibrot"))
		l->var = 2;
	if (!ft_strcmp(av[1], "Feigenbaum"))
		l->var = 3;
}

int			main(int ac, char **av)
{
	t_fract		l;

	if (ac == 2)
	{
		help1(&l, av);
		if (l.var != 5)
		{
			l.mlx_ptr = mlx_init();
			l.win_ptr = mlx_new_window(l.mlx_ptr, S + 300, S, "Fractol");
			init(&l);
			draw(&l);
			menu(l);
			mlx_hook(l.win_ptr, 2, 0, &key_press, &l);
			mlx_hook(l.win_ptr, 6, 0, &mouse_move, &l);
			mlx_hook(l.win_ptr, 4, 0, &mouse_press, &l);
			mlx_loop(l.mlx_ptr);
		}
		else
			gestion_error();
	}
	else
		gestion_error();
	return (0);
}
