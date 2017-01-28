/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:18:47 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/03 15:22:03 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	i = 0;
	c1 = (unsigned char *)dst;
	c2 = (unsigned char *)src;
	while (i < n)
	{
		c1[i] = c2[i];
		if (c1[i] == (unsigned char)c)
			return (c1 + i + 1);
		i++;
	}
	return (NULL);
}
