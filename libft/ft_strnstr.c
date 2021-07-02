/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/07/02 15:23:12 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	length;

	length = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	if (length <= n)
	{
		while (*s1 && n - length + 1 > 0)
		{
			if (*s1 == *s2)
			{
				if (ft_memcmp((char *)s1, (char *)s2, length) == 0)
					return ((char *)s1);
			}
			s1++;
			n--;
		}
	}
	return (NULL);
}
