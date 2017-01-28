/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:06:25 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/04 14:16:34 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	size_t	i;
	char	*map;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	if (!(map = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (s && f)
	{
		while (size > i)
		{
			map[i] = f(s[i]);
			i++;
		}
		map[i] = '\0';
	}
	return (map);
}
