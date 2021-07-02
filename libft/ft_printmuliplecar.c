/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmuliplecar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:09:43 by sbeline           #+#    #+#             */
/*   Updated: 2021/07/02 15:13:42 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void	ft_printmuliplecar(int nb, char c)
{
	while (nb >= 0)
	{
		--nb;
		ft_putchar(c);
	}
}
