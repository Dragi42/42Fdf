/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:00:18 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/03 17:34:35 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	operator(int *n, int *len)
{
	if (*n < 0)
	{
		*n = -*n;
		*len += 1;
	}
}

char		*ft_itoa(int n)
{
	int		tmp;
	int		len;
	char	*str;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = 2;
	neg = (n >= 0) ? 0 : 1;
	operator(&n, &len);
	tmp = n;
	while (tmp /= 10)
		len++;
	if (!(str = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (neg == 1)
		str[0] = '-';
	return (str);
}
