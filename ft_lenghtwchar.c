/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lenghtwchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/07/02 15:38:18 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

int 	ft_lenghtwchar(wchar_t wc)
{
	if (wc < (1 << 7))
		return (1);
	else if (wc < (1 << 11))
		return (2);
	else if (wc < (1 << 16))
		return (3);
	else if (wc < (1 << 21))
		return (4);
	return (-1);
}
