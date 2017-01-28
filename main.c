/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:26:24 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/01/28 18:04:19 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"

void	draw(t_env *e)
{
	int	k;
	int	l;

	e->i = e->size_x / 10;
	e->x = 0;
	while (e->x < e->line)
	{
		e->y = 0;
		e->j = e->size_y / 10;
		while (e->y < e->nb)
		{
			k = e->j + ((e->size_x / 2) / e->nb);
			if (e->map[e->x][e->y] == 0)
			{
				while (e->j < k)
				{
					mlx_pixel_put(e->mlx, e->win, e->j, e->i, 0xFFFFFF);
					e->j++;
				}
				k = e->i + ((e->size_x / 2) / e->nb);
				while (e->i < k)
				{
					mlx_pixel_put(e->mlx, e->win, e->j, e->i, 0xFFFFFF);
					e->i++;
				}
				e->i -= ((e->size_x / 2) / e->nb);
			}
			else
			{
				while (e->j < k)
				{
					mlx_pixel_put(e->mlx, e->win, e->j, e->i, 0xFF0000);
					e->j++;
				}
				k = e->i + ((e->size_x / 2) / e->nb);
				while (e->i < k)
				{
					mlx_pixel_put(e->mlx, e->win, e->j, e->i, 0xFF0000);
					e->i++;
				}
				e->i -= ((e->size_x / 2) / e->nb);
			}
			e->y++;
		}
		e->x++;
		e->i += ((e->size_y / 2) / e->line);
	}
}

int		key_hook(int keycode, t_env *e)
{
	printf("key code : %d\n", keycode);
	if (keycode == 53)
		exit(0);
	return (0);
}
/*
int		mouse_hook(int button, int x, int y, t_env *e)
{
	printf("mouse : %d (%d:%d)\n", button, x, y);
	return (0);
}*/

int		expose_hook(t_env *e)
{
	draw(e);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	e;

	e.size_x = 1920;
	e.size_y = 1080;
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
//			mlx_mouse_hook(e.win, mouse_hook, &e);
			mlx_loop(e.mlx);
		}
		else
			ft_putstr("File error\n");
	}
	return (0);
}
