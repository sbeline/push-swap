/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunlong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2021/07/02 15:19:19 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Includes/libft.h"

void 	ft_printunlong(unsigned long long ll)
{
	int		printlldiv;
	int		printllmod;

	printlldiv = 0;
	printllmod = 0;
	if (ll >= 10)
	{
		printlldiv = ll / 10;
		printllmod = ll % 10;
		ft_printunlong(printlldiv);
		ft_printunlong(printllmod);
	}
	else
		ft_putchar(ll + '0');
}
