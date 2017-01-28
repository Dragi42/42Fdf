/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:33:33 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/03 17:36:40 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*next;

	if (*alst == NULL)
		return ;
	(*del)((*alst)->content, (*alst)->content_size);
	next = (*alst)->next;
	free(*alst);
	while (next)
	{
		tmp = next;
		next = next->next;
		(*del)((tmp)->content, (tmp)->content_size);
		free(tmp);
	}
	*alst = NULL;
}
