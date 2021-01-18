/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			checker(char *buf, t_dllist *stack_a, t_dllist *stack_b)
{
	if (!ft_strcmp(buf, "sa"))
		return (swap(stack_a, NULL, 0));
	if (!ft_strcmp(buf, "sb"))
		return (swap(NULL, stack_b, 1));
	if (!ft_strcmp(buf, "ss"))
		return (swap(stack_a, stack_b, 2));
	if (!ft_strcmp(buf, "ra"))
		return (ft_rotate(stack_a, NULL, 0));
	if (!ft_strcmp(buf, "rb"))
		return (ft_rotate(NULL, stack_b, 1));
	if (!ft_strcmp(buf, "rr"))
		return (ft_rotate(stack_a, stack_b, 2));
	if (!ft_strcmp(buf, "rra"))
		return (ft_rrotate(stack_a, NULL, 0));
	if (!ft_strcmp(buf, "rrb"))
		return (ft_rrotate(NULL, stack_b, 1));
	if (!ft_strcmp(buf, "rrr"))
		return (ft_rrotate(stack_a, stack_b, 2));
	return (-1);
}

void view_stack(t_dllist *a, t_dllist *b, int maxLenghtNb)
{
	printf("[%d]\n", maxLenghtNb);
}

int			main(int ac, char **av)
{
	t_dllist	*stack_a;
	t_dllist	*stack_b;
	char			*buf;
	int				maxLenghtNb;

	ac--;
	av++;
	stack_a = NULL;
	stack_b = NULL;
	maxLenghtNb = 0;
	if (!ac)
		return (-1);
	if ((stack_a = validate_and_stacka(av, ac, &maxLenghtNb)) == NULL)
		return (-1);
	view_stack(stack_a, stack_b,maxLenghtNb);
	while ((get_next_line(1, &buf)) > 0)
	{
		if ((checker(buf, stack_a, stack_b)) != -1 || !ft_strcmp(buf,"pa") || !ft_strcmp(buf,"pb"))
		{
			if (!ft_strcmp(buf, "pa"))
				push(&stack_b, &stack_a);
			if (!ft_strcmp(buf, "pb"))
				push(&stack_a, &stack_b);
			view_stack(stack_a, stack_b, maxLenghtNb);
		}
		else{
			view_stack(stack_a, stack_b, maxLenghtNb);
			return (stack_is_ok(stack_a, stack_b));
		}
	}
	return (0);
}

void tmp(t_dllist *a, t_dllist *b, int maxLenghtNb)
{
	/* code */
	t_llist *lst_a;
	t_llist *lst_b;
	int count;
	int countA;
	int countB;

	int lenghtA;
	int lenghtB;
	lenghtA =  (a) ? a->lenght : 0;
	lenghtB =  (b) ? b->lenght : 0;
	printf("lenghtA=%dlenghtB=%d\n", lenghtA,lenghtB);
	count = (lenghtA >= lenghtB) ? lenghtA : lenghtB;
	lst_a = NULL;
	lst_b = NULL;
	if (	lenghtA || 	lenghtB)
	{
		if (a && a->head) {
			lst_a = (lenghtA) ? a->head : NULL;
		}
		if (b && b->head) {
			lst_b = (lenghtB) ? b->head : NULL;

		}
		while (lst_a || lst_b){
			/*ft_putstr("<->");
			ft_putnbr(lenghtA );
			ft_putstr("<->");
			ft_putnbr(lenghtB );*/
			if(lst_a && lenghtA >= lenghtB)
			{
				ft_putnbr(lst_a->content );
				if ( lenghtA > lenghtB)
				{
					ft_putchar('\n');
				}
				lst_a = lst_a->next;

			}
			if(lst_b && lenghtB >= lenghtA)
			{
				if (lenghtB > lenghtA) {
					/* code */
					ft_putchar(' ');
				}
				ft_putnbr(lst_b->content );

				if ( lenghtB >= lenghtA)
				{
					ft_putchar('\n');
				}
				lst_b = lst_b->next;
			}
			countA = lenghtA;
			countB = lenghtB;
			lenghtA = (lenghtA && (lenghtA >= countB))? lenghtA - 1 :lenghtA;
			lenghtB = (lenghtB && (lenghtB >= countA))? lenghtB - 1 :lenghtB;
		}
	}
}
