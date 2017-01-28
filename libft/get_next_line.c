/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 14:33:48 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/01/06 16:34:00 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file	*ft_filenew(int fd)
{
	t_file	*new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		return (NULL);
	new->str = ft_strnew(0);
	new->fd = fd;
	new->next = NULL;
	return (new);
}

static int		bufftolst(t_file **lst, int fd)
{
	char	*tmp;
	char	buff[BUFF_SIZE + 1];
	int		rd;

	while (!(ft_strchr((*lst)->str, '\n')))
	{
		if ((rd = read(fd, buff, BUFF_SIZE)) > 0)
		{
			buff[rd] = '\0';
			tmp = ft_strjoin((*lst)->str, buff);
			free((*lst)->str);
			(*lst)->str = ft_strdup(tmp);
			free(tmp);
		}
		else if (rd == 0)
			return (0);
		if (rd < 0)
			return (-1);
	}
	return (1);
}

static t_file	*ft_checklst(t_file **lst, int fd)
{
	t_file	*tmp;

	if (!(*lst) || (*lst)->str == NULL)
		*lst = ft_filenew(fd);
	tmp = (*lst);
	while (tmp->fd != fd)
	{
		if (tmp->next == NULL)
		{
			tmp->next = ft_filenew(fd);
			return (tmp->next);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*lst = NULL;
	t_file			*file;
	char			*tmp;
	int				rd;
	int				delline;

	file = ft_checklst(&lst, fd);
	rd = bufftolst(&file, fd);
	if (rd < 0)
		return (-1);
	if (!ft_strlen(file->str))
		return (0);
	*line = ft_strndup(file->str, ft_strcspn(file->str, "\n"));
	if (ft_strchr(file->str, '\n'))
	{
		delline = ft_strlen(file->str) - ft_strcspn(file->str, "\n");
		tmp = ft_strsub(file->str, ft_strcspn(file->str, "\n") + 1, delline);
		free(file->str);
		file->str = ft_strdup(tmp);
		free(tmp);
	}
	else
		ft_strdel(&file->str);
	return (1);
}
