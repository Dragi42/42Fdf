/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:08:43 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/04 14:19:56 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	if (dst != NULL)
	{
		ft_strcpy((char *)dst, s1);
		ft_strcat((char *)dst, s2);
	}
	return (dst);
}
