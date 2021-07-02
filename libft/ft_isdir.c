/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/06/16 07:14:26 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int 	is_dir(char *s)
{
	struct stat	buf;
	int			i;

	i = 0;
	if (stat(s, &buf) == -1)
		return (-1);
	if (S_ISREG(buf.st_mode))
		i = 50;
	if (S_ISDIR(buf.st_mode))
		i = 60;
	if (S_ISLNK(buf.st_mode))
		i = 70;
	return (i);
}
