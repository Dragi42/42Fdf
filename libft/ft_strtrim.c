/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:49:51 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/04 15:31:07 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*s1;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (*s && (*s == ' ' || *s == '\n' || *s == '\t'))
		s++;
	if (*s == '\0')
		return (ft_strdup(s));
	i = ft_strlen((char *)s);
	while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\n' || s[i - 1] == '\t'))
		i--;
	if (!(s1 = ft_strnew(i + 1)))
		return (NULL);
	ft_strncpy(s1, s, i);
	if (s1)
		s1[i] = '\0';
	return (s1);
}
