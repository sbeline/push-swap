/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_gest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <sbeline@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 14:10:17 by sbeline           #+#    #+#             */
/*   Updated: 2021/08/26 16:03:10 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int 	stack_raw_is_merge(t_dllist *stack)
{
	t_llist		*ptr;
	int			nb;

	if ((stack) == NULL)
		return (1);
	if (!stack->last_entry_smallest->next)
		ptr = stack->head;
	else
		ptr = stack->last_entry_smallest->next;
	while (!ptr->smallest)
	{
		if (ptr->next)
		{
			if (!ptr->next->smallest && ptr->content > ptr->next->content)
				return (0);
			ptr = ptr->next;
		}
		else
		{
			if (!stack->head->smallest && ptr->content > stack->head->content)
				return (0);
			ptr = stack->head;
		}
	}
	return (1);
}

int 	stack_is_merge(t_dllist *stack)
{
	t_llist		*ptr;
	int			nb;

	if ((stack) == NULL)
		return (-1);
	ptr = stack->head;
	while (ptr->next)
	{
		if (ptr->content > ptr->next->content)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}

int 	control(char *av, t_dllist **stack)
{
	t_llist		*ptr;
	int			nb;
	int			i;

	i = 0;
	if ((*stack) == NULL)
		return (1);
	ptr = (*stack)->head;
	while (av[i])
		if (!ft_isdigit(av[i++]))
			return (-1);
	nb = ft_atoi(av);
	while (ptr)
	{
		if (nb == ptr->content)
			return (-2);
		ptr = ptr->next;
	}
	return (0);
}

t_dllist	*error_gest(t_dllist **stack, int cod)
{
	t_llist		*ptr;
	t_llist		*ptr_next;

	if (cod == -1)
		ft_putendl("stack invalid: invalid input");
	else if (cod == -2)
		ft_putendl("stack invalid: number already set");
	ptr = (*stack)->head;
	if (ptr)
	{
		ptr_next = ptr->next;
		ptr->content = '0';
		free(ptr);
		ptr = ptr_next;
	}
	return (NULL);
}
