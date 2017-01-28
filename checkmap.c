/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:02:24 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/01/28 16:19:53 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

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


	/*	Hors Norme, 27 lignes	*/

int			lst_tab(t_list *lst, t_env *e)
{
	char	**tab;

	e->x = 0;
	e->y = 0;
	e->line = ft_lstlen(lst);
	if (!(e->map = (int **)ft_memalloc(sizeof(int *) * e->line)))
		return (0);
	while (lst)
	{
		tab = ft_strsplit(lst->content, ' ');
		e->y = 0;
		if (e->nb && ft_tabslen(tab) != e->nb)
			return (0);
		e->nb = ft_tabslen(tab);
		if (!(e->map[e->x] = (int *)ft_memalloc(sizeof(int) * e->nb)))
			return (0);
		while (tab[e->y])
		{
			e->map[e->x][e->y] = ft_atoi(tab[e->y]);
			free(tab[e->y]);
			e->y++;
		}
		free(tab);
		free(lst);
		lst = lst->next;
		e->x++;
	}

	/*	Test affichage e->map	*/
	e->x = 0;
	while (e->x < e->line)
	{
		e->y = 0;
		while (e->y < e->nb)
		{
			printf("%d ", e->map[e->x][e->y]);
			e->y++;
		}
		printf("\n");
		e->x++;
	}
	/*---------------------------*/
	return (1);
}
