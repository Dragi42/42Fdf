/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 16:26:56 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/28 16:30:38 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	if (!(s2 = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (n)
	{
		s2[i] = s1[i];
		i++;
		n--;
	}
	s2[i] = '\0';
	return (s2);
}
