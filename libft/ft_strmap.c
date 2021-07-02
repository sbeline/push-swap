/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/07/02 15:33:17 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str_res;
	int		i;

	if (!s || !f)
		return (NULL);
	str_res = ft_strdup((char *)s);
	if (!str_res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str_res[i] = f(s[i]);
		i++;
	}
	str_res[i] = '\0';
	return (str_res);
}
