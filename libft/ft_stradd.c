/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/07/02 15:26:24 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_stradd(char **s1, char **s2)
{
	char	*str;
	void	*b;
	int		i;

	i = ft_strlen(*s1) + ft_strlen(*s2);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!(str))
		return (NULL);
	b = str;
	i = 0;
	while ((*s1)[i])
		*str++ = (*s1)[i++];
	i = 0;
	while ((*s2)[i])
		*str++ = (*s2)[i++];
	*str = '\0';
	if (*s1)
		ft_strdel(s1);
	if (*s2)
		ft_strdel(s2);
	return (b);
}
