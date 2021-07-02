/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_name.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/06/16 07:22:55 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int 	ft_strcmp_name(char *s1, char *s2)
{
	char	c1;
	char	c2;

	while (*s1 == *s2)
	{
		s2++;
		s1++;
	}
	if (*s1 >= 'A' && *s1 <= 'Z')
		c1 = *s1 + 32;
	if (*s2 >= 'A' && *s2 <= 'Z')
		c2 = *s2 + 32;
	if (c2 < c1)
		return (1);
	return (-1);
}
