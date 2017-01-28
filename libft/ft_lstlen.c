/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:24:57 by dpaunovi          #+#    #+#             */
/*   Updated: 2017/01/25 18:50:46 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_lstlen(t_list *lst)
{
	int		nb;

	nb = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		nb++;
	}
	return (nb);
}
