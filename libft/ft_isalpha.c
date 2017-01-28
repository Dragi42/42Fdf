/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 17:12:39 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/11/24 15:52:37 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	unsigned char a;
	unsigned char b;

	a = 'a';
	b = 'A';
	while (a < 'z' && a != c)
		a++;
	while (b < 'Z' && b != c)
		b++;
	if (b == c || a == c)
		return (1);
	else
		return (0);
}
