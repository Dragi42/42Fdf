/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:09:00 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/03/29 16:55:48 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct	s_map
{
	int			x;
	int			y;
	int			z;
}				t_map;

typedef	struct	s_point
{
	int			x;
	int			dx;
	int			sx;
	int			y;
	int			dy;
	int			sy;
	int			err1;
	int			err2;
}				t_point;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			size_x;
	int			size_y;
	int			line;
	int			nb;
	int			z;
	int			mode;
	int			moveh;
	int			movev;
	char		**tab;
	t_map		**map;
	int			depth;
	int			i;
	int			j;
	t_point		p;
	int			bpp;
	int			sizeline;
	int			endian;
	short		rcolor;
	short		gcolor;
	short		bcolor;
	char		*data;
}				t_env;

int				lst_tab(t_list *lst, t_env *e);
t_list			*file_lst(char *argv);
void			segput(t_env *e);

#endif
