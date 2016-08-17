/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salomon <salomon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 06:32:38 by salomon           #+#    #+#             */
/*   Updated: 2016/08/14 01:34:57 by salomon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push-swap.h"
#include "../libft/Includes/libft.h"

static t_dllist		*validate_and_stacka(char **av, int ac)
{
	t_dllist *stack;
	char	*ptr;
	int		i;

	i = 0;
	stack = NULL;
	while (i < ac)
	{
		ptr = av[i];
		while (*ptr)
		{
			if (!ft_isdigit(*ptr))
			{
				ft_putendl("ERROR:wrong input");
				exit (1);
			}
			ptr++;
		}
		ft_lstadd(&stack, ft_lstnew(av[i], ft_strlen(av[i])));
		i++;
	}
	return (stack);
}

static int 		checker(t_dllist **alst, int lenght)
{
	if (lenght < 8)
	{
		
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_dllist	*stack_a;
	t_llist		*ptr;

	ac--;
	av++;
	stack_a = NULL;
	if (!ac)
		return (-1);
	stack_a = validate_and_stacka(av, ac);
	checker(&stack_a, ac);
/*	ptr = stack_a->tail;
	while (ptr)
	{
		ft_putendl((const char*)ptr->content);
		ptr = ptr->prev;
	}*/
	ptr = stack_a->head;
	while (ptr)
	{
		ft_putendl((const char*)ptr->content);
		ptr = ptr->next;
	}
	return (0);
}
