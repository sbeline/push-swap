/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/06/16 07:42:05 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

char	*ft_strnew(size_t size, const char *s)
{
	char	*tmp;
	void	*begin;

	tmp = (char *)malloc(sizeof(char) * (size + 1));
	if (tmp)
	{
		begin = tmp;
		while (*s && size--)
			*tmp++ = *s++;
		*tmp = '\0';
		return (begin);
	}
	return (NULL);
}
