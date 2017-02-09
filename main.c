/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:26:24 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/02/09 22:54:00 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

void	draw(t_env *e)
{
	segput(e);
}

int		expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	draw(e);
	return (0);
}

int		key_hook(int keycode, t_env *e)
{
//	printf("key code : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	if (keycode == 48)
	{
		if (e->mode == 1)
			e->mode = 0;
		else
			e->mode = 1;
	}
	if (keycode == 69)
		e->z += 1;
	if (keycode == 78)
	{
		if (e->z > 1)
			e->z -= 1;
	}
	if (keycode == 35)
		e->depth += 1;
	if (keycode == 37)
		e->depth -= 1;
	if (keycode == 36)
	{
		e->depth = 0;
		e->z = 1;
		e->moveh = 50;
		e->movev = 50;
	}
	if (keycode == 124)
		e->moveh += 100;
	if (keycode == 123)
		e->moveh -= 100;
	if (keycode == 126)
		e->movev -= 100;
	if (keycode == 125)
		e->movev += 100;
	expose_hook(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
//	printf("mouse : %d (%d:%d)\n", button, x, y);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	e.size_x = 1280;
	e.size_y = 720;
	if (argc != 2)
		return (0);
	else
	{
		if (lst_tab(file_lst(argv[1]), &e))
		{
			e.mlx = mlx_init();
			e.win = mlx_new_window(e.mlx, e.size_x, e.size_y, "FDF");
			mlx_key_hook(e.win, key_hook, &e);
			mlx_expose_hook(e.win, expose_hook, &e);
			mlx_mouse_hook(e.win, mouse_hook, &e);
			mlx_loop(e.mlx);
		}
		else
			ft_putstr("File error\n");
	}
	return (0);
}
