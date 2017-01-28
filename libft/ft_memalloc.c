/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:10:17 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/01 18:26:30 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (!size)
		return (NULL);
	if (!(mem = (void *)malloc(sizeof(void) * size)))
		return (NULL);
	ft_memset(mem, 0, size);
	return (mem);
}
