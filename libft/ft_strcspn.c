/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:09:24 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/11/30 19:32:23 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i] && ft_charcmp(s[i], (char *)reject))
	{
		count++;
		i++;
	}
	return (count);
}
