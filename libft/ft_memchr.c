/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:45:01 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/01 16:29:25 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;
	unsigned char	c2;

	c2 = (unsigned char)c;
	str = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (str[i] == c2)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
