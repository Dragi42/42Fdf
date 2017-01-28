/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 15:15:23 by dpaunovi          #+#    #+#             */
/*   Updated: 2016/12/27 15:21:31 by dpaunovi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_replace_char(char *str, char c1, char c2)
{
	while (ft_strcspn(str, &c1))
		str[ft_strcspn(str, &c1)] = c2;
	return (str);
}
