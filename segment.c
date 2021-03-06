/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:04:37 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/04/05 10:55:40 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

static void	ft_3d(t_env *e)
{
	int		y;
	int		x;

	y = -1;
	while (++y < e->line)
	{
		x = -1;
		while (++x < e->nb)
		{
			if (e->map[y][x].z > 0)
			{
				e->map[y][x].x -= (e->map[y][x].z + e->depth) / e->nb;
				e->map[y][x].y -= (e->map[y][x].z + e->depth) * e->line;
			}
			else if (e->map[y][x].z < 0)
			{
				e->map[y][x].x += (e->map[y][x].z + e->depth) / e->nb;
				e->map[y][x].y += (e->map[y][x].z + e->depth) * e->line;
			}
		}
	}
}

static void	pixel_put(t_env *e, t_map p1, t_map p2)
{
	short		r;
	short		g;
	short		b;

	r = 0xFF;
	g = 0x00;
	b = 0x00;
	if (e->map[e->i][e->j].z == 0)
		r = 0xff;
	else if ((e->map[e->i][e->j].z + e->depth) > 0)
		g = 0xff;
	else if ((e->map[e->i][e->j].z + e->depth) < 0)
		b = 0xff;
	if (p1.x < e->size_x && p1.y < e->size_y &&
			p1.x > 0 && p1.y > 0)
	{
		e->data[p1.y * e->sizeline + p1.x * e->bpp / 8] = b + e->bcolor;
		e->data[p1.y * e->sizeline + p1.x * e->bpp / 8 + 1] = g + e->gcolor;
		e->data[p1.y * e->sizeline + p1.x * e->bpp / 8 + 2] = r + e->rcolor;
	}
}

static void	ft_draw_line(t_env *e, t_map p1, t_map p2)
{
	e->p.dx = abs(p2.x - p1.x);
	e->p.dy = abs(p2.y - p1.y);
	e->p.sx = (p1.x < p2.x) ? 1 : -1;
	e->p.sy = (p1.y < p2.y) ? 1 : -1;
	e->p.err1 = (e->p.dx > e->p.dy ? e->p.dx : -e->p.dy) / 2;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		e->p.err2 = e->p.err1;
		if (e->p.err2 >= -e->p.dx)
		{
			e->p.err1 -= e->p.dy;
			p1.x += e->p.sx;
		}
		if (e->p.err2 <= e->p.dy)
		{
			e->p.err1 += e->p.dx;
			p1.y += e->p.sy;
		}
		pixel_put(e, p1, p2);
	}
}

static void	win_pos(t_env *e)
{
	e->p.y = 0;
	e->i = 0;
	e->p.dx = 20;
	while (e->i < e->line)
	{
		e->j = 0;
		e->p.x = 0;
		while (e->j < e->nb)
		{
			e->map[e->i][e->j].x = e->moveh + (e->p.x - e->p.y);
			e->map[e->i][e->j].y = e->movev + (e->p.x + e->p.y);
			e->p.x += e->p.dx + e->z;
			e->j++;
		}
		e->i++;
		e->p.y += e->p.dx + e->z;
	}
}

void		segput(t_env *e)
{
	win_pos(e);
	ft_3d(e);
	e->i = 0;
	while (e->i < e->line)
	{
		e->j = 0;
		while (e->j < e->nb)
		{
			if (e->i < e->line - 1)
				ft_draw_line(e, e->map[e->i][e->j], e->map[e->i + 1][e->j]);
			if (e->j < e->nb - 1)
				ft_draw_line(e, e->map[e->i][e->j], e->map[e->i][e->j + 1]);
			e->j++;
		}
		e->i++;
	}
}
