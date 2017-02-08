/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:02:24 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/02/06 17:31:58 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	struct_init(t_list *lst, t_env *e)
{
	e->p.x = 0;
	e->p.y = 0;
	e->nb = 0;
	e->line = ft_lstlen(lst);
}

t_list		*file_lst(char *argv)
{
	t_list	*lst;
	char	*line;
	int		fd;
	int		rd;

	lst = NULL;
	line = NULL;
	if ((fd = open(argv, O_RDONLY)) == -1)
		return (NULL);
	while ((rd = get_next_line(fd, &line)) == 1)
	{
		if (!lst)
			lst = ft_lstnew(line, ft_strlen(line) + 1);
		else
			ft_lstaddend(&lst, line, ft_strlen(line) + 1);
	}
	close(fd);
	free(line);
	return (lst);
}

	/*	Hors Norme, 26 lignes	*/

int			lst_tab(t_list *lst, t_env *e)
{
	char	**tab;

	struct_init(lst, e);
	if (!(e->map = (t_map **)ft_memalloc(sizeof(t_map *) * e->line)))
		return (0);
	while (lst)
	{
		tab = ft_strsplit(lst->content, ' ');
		e->p.y = 0;
		if (e->nb && ft_tabslen(tab) != e->nb)
			return (0);
		e->nb = ft_tabslen(tab);
		if (!(e->map[e->p.x] = (t_map *)ft_memalloc(sizeof(t_map) * e->nb)))
			return (0);
		while (tab[e->p.y])
		{
			e->map[e->p.x][e->p.y].z = ft_atoi(tab[e->p.y]);
			free(tab[e->p.y]);
			e->p.y++;
		}
		free(tab);
		free(lst);
		lst = lst->next;
		e->p.x++;
	}

	/*	Test affichage e->map	*/
	e->p.x = 0;
	while (e->p.x < e->line)
	{
		e->p.y = 0;
		while (e->p.y < e->nb)
		{
			printf("%d ", e->map[e->p.x][e->p.y].z);
			e->p.y++;
		}
		printf("\n");
		e->p.x++;
	}
	/*---------------------------*/
	return (1);
}
