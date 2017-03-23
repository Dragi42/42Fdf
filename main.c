/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:26:24 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/03/22 19:58:44 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

int		expose_hook(t_env *e)
{
//	mlx_clear_window(e->mlx, e->win);
	e->img = mlx_new_image(e->mlx, e->size_x, e->size_y);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->sizeline), &(e->endian));
	e->color = mlx_get_color_value(e->mlx, 0xFF0000);
	segput(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	ft_key(int keycode, t_env *e)
{
	if (keycode == 69)
		e->z += 1;
	if (keycode == 78)
		e->z -= 1;
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
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 48)
	{
		if (e->mode == 1)
			e->mode = 0;
		else
			e->mode = 1;
	}
	ft_key(keycode, e);
	expose_hook(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	e.size_x = 1280;
	e.size_y = 720;
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf [source_file]");
		return (0);
	}
	else
	{
		if (lst_tab(file_lst(argv[1]), &e))
		{
			e.mlx = mlx_init();
			e.win = mlx_new_window(e.mlx, e.size_x, e.size_y, "FDF");
			mlx_key_hook(e.win, key_hook, &e);
			mlx_expose_hook(e.win, expose_hook, &e);
			mlx_loop(e.mlx);
		}
		else
			ft_putstr("File error\n");
	}
	return (0);
}
