/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeddaqqa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 11:40:56 by aeddaqqa          #+#    #+#             */
/*   Updated: 2019/09/30 12:14:23 by aeddaqqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		part2_iter(int keycode, t_fract *l)
{
	if (l->var == 2)
	{
		if (keycode == 69)
			l->m.iter_max += 10;
		else if (keycode == 78 && l->m.iter_max > 50)
			l->m.iter_max -= 10;
	}
	else if (l->var == 3)
	{
		if (keycode == 69)
			l->q.iter_max += 10;
		else if (keycode == 78 && l->q.iter_max > 50)
			l->q.iter_max -= 10;
	}
}

void		ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void		gestion_error(void)
{
	ft_putstr(" ____________________________\n");
	ft_putstr("| usage : fractol [fractals] |\n");
	ft_putstr("|____________________________|\n");
	ft_putstr("|         fractals :         |\n");
	ft_putstr("|____________________________|\n");
	ft_putstr("|   --> Mandelbrot           |\n");
	ft_putstr("|   --> Julia                |\n");
	ft_putstr("|   --> Multibrot            |\n");
	ft_putstr("|   --> Feigenbaum           |\n");
	ft_putstr("|____________________________|\n");
}

void		guide(t_fract *l)
{
	mlx_string_put(l->mlx_ptr, l->win_ptr, 910, 50,
			0x34495E, "COMMANDS");
	mlx_string_put(l->mlx_ptr, l->win_ptr, 850, 450, 0x34495E,
			"RESTART      : r");
	mlx_string_put(l->mlx_ptr, l->win_ptr, 850, 250, 0x34495E,
			"COLOR        : c / v");
	mlx_string_put(l->mlx_ptr, l->win_ptr, 850, 350, 0x34495E,
			"ITER_MAX     : + / -");
	mlx_string_put(l->mlx_ptr, l->win_ptr, 850, 150, 0x34495E,
			"ZOOM +/-     : mouse");
	mlx_string_put(l->mlx_ptr, l->win_ptr, 850, 550, 0x34495E,
			"CHANGE FRACT : w / e");
	mlx_string_put(l->mlx_ptr, l->win_ptr, 850, 650, 0x34495E,
			"TRANSLATION  : ARROW");
	mlx_string_put(l->mlx_ptr, l->win_ptr, 850, 750, 0x34495E,
			"JULIA FREEZ  : SPACE");
}

void		menu(t_fract l)
{
	int		x;
	int		z;

	x = 800;
	while (++x < 1100)
	{
		z = -1;
		while (++z < 800)
			mlx_pixel_put(l.mlx_ptr, l.win_ptr, x, z, 0xCEF1EF);
	}
	guide(&l);
}
