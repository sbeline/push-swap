/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:12:03 by sbeline           #+#    #+#             */
/*   Updated: 2021/07/28 17:29:51 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int 	check_list_integrity(t_dllist *stack, int entry)
{
	t_llist		*ptr;

	ptr = stack->head;
	while (ptr)
	{
		if (entry == ptr->content)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

t_dllist 	*validate_and_stacka(char **av, int ac, int *maxLenghtNb)
{
	t_dllist	*stack;
	char		*ptr;
	int			cod;
	int			i;

	i = 0;
	stack = NULL;
	while (i < ac)
	{
		cod = control(av[i], &stack);
		if (cod < 0)
			return (error_gest(&stack, cod));
		if (*maxLenghtNb < ft_nblen(ft_atoi(av[i])))
			*maxLenghtNb = ft_nblen(ft_atoi(av[i]));
		ft_lstadd(&stack, ft_lstnew(ft_atoi(av[i]), sizeof(int)));
		i++;
	}
	return (stack);
}
