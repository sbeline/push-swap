/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/06/16 07:36:51 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[k])
	{
		while (s1[i])
		{
			j = 0;
			while (s1[i++] == s2[j++])
				if (s2[j] == '\0')
					return ((char *)s1 + (i - j));
			if (s1[i] == s2[0])
				i--;
			i++;
		}
		k++;
		i = k;
	}
	return (NULL);
}
