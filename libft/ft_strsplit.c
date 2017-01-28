/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 22:19:33 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/03 17:34:04 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		value(char *s, char c, int val[2])
{
	int nb_w;
	int n;
	int max_len;
	int len_w;

	n = 0;
	nb_w = 0;
	max_len = 0;
	while (s[n])
	{
		len_w = 0;
		while (s[n] == c)
			n++;
		if (s[n] != c && s[n] != 0)
			nb_w++;
		while (s[n] != c && s[n] != 0)
		{
			len_w++;
			n++;
		}
		if (len_w > max_len)
			max_len = len_w;
	}
	val[0] = nb_w;
	val[1] = max_len;
}

static char		*file(char const *s, char c, int *i, int val[1])
{
	int		n;
	char	*str;

	while (s[*i] == c)
		*i += 1;
	if (!(str = (char*)malloc(sizeof(char) * (val[1] + 1))))
		return (NULL);
	n = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		str[n] = s[*i];
		*i += 1;
		n++;
	}
	str[n] = 0;
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		val[2];
	int		n;
	int		i;

	n = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	value((char*)s, c, val);
	if (!(tab = (char**)malloc(sizeof(char*) * (val[0] + 1))))
		return (NULL);
	while (n < val[0])
	{
		tab[n] = file(s, c, &i, val);
		n++;
	}
	tab[n] = 0;
	return (tab);
}
