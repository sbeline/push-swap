/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/06/22 19:21:54 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int 	nblen(int n)
{
	if (n < 0)
		return (1 + nblen(-n));
	if (n < 10)
		return (1);
	return (1 + nblen(n / 10));
}

int 	is_neg(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

int 	convert_neg(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	int		i;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = is_neg(n);
	len = nblen(n);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str)
	{
		n = convert_neg(n);
		i = len - 1;
		while (i >= neg)
		{
			str[i] = (n % 10) + 48;
			n /= 10;
			i--;
		}
		if (neg)
			str[0] = '-';
		str[len] = '\0';
	}
	return (str);
}
