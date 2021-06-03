#include "../../includes/push_swap.h"

static int		swap_check(t_dllist *stack_a, t_dllist *stack_b, int a, int b)
{
	if (!a && stack_a && stack_a->head->next &&
		 stack_a->head->content > stack_a->head->next->content &&
		 !b && stack_b &&stack_b->head->next &&
		 stack_b->head->content > stack_b->head->next->content) {
		swap(stack_a, stack_b, 2);
		return(1);
	}
	if (!a && stack_a && stack_a->head->next &&
		 stack_a->head->content > stack_a->head->next->content) {
		swap(stack_a, NULL, 0);
		return(1);
	}
	if (!b && stack_b &&stack_b->head->next &&
		 stack_b->head->content > stack_b->head->next->content) {
		swap(NULL, stack_b, 1);
		return(1);
	}
	return(0);
}

static t_dllist	*divide_stack(t_dllist *stack_a, int midLenghtStack)
{
	t_dllist *stack_b;
	int count;

	count = 0;
	stack_b = NULL;
	while (count != midLenghtStack)
	{
		push(&stack_a, &stack_b);
		ft_putstr("[pb]");
		count++;
	}
	//determine smallest for each stack
	rest_src(stack_a, stack_b);
	view_stack(stack_a, NULL, 42);
	view_stack(stack_b, NULL, 42);
	return (stack_b);
}

static void fusion_merge(t_dllist *stack_a, t_dllist *stack_b)
{
  int count;

  count = 0;
  while ((stack_is_merge(stack_a) || stack_b) && count < stack_a->lenght)
  {
    if (stack_b && stack_b->head->content < stack_a->head->content)
		{
      push(&stack_b, &stack_a);
			ft_putstr("[pb]");
		}
    else if (stack_b->head->content > stack_a->head->content)
    {
      ft_rotate(stack_a, NULL, 0);
      count++;
    }
  }
  while (!stack_a->head->smallest)
  {
    ft_rotate(stack_a, NULL, 0);
  }
}

void merge_stack_brut(t_dllist *stack_a, t_dllist *stack_b)
{
	int a_merge;
	int b_merge;
  int count_rotate_a;
	int count_rotate_b;

	a_merge = 0;
	b_merge = 0;
  count_rotate_a = 0;
	count_rotate_b = 0;
	while (!(a_merge = stack_is_merge(stack_a)) ||
	 	!(b_merge = stack_is_merge(stack_b)))
	{
		if (!swap_check(stack_a, stack_b, a_merge, b_merge))
		{
			if (!a_merge && !b_merge && count_rotate_a < stack_a->lenght
					&& count_rotate_b < stack_b->lenght)
					{
						ft_rotate(stack_a, stack_b, 2);
						count_rotate_a++;
						count_rotate_b++;
					}
			else {
				if (!a_merge && count_rotate_a < stack_a->lenght)
				{
					ft_rotate(NULL, stack_b, 1);
					count_rotate_a++;
				}
				else if (!b_merge && count_rotate_b < stack_b->lenght)
				{
					ft_rotate(stack_a, NULL, 0);
					count_rotate_b++;
				}
			}
			if (stack_a->head->lastest)
			{
				ft_putstr("in");
				rest_stack(stack_a, NULL);
			}
			if (stack_b->head->lastest)
			{
				ft_putstr("in");
				rest_stack(NULL, stack_b);
			}
		}

		view_stack(stack_a, stack_b, 42);


	/*	if (!a_merge && stack_a && stack_a->head->next){
      ft_rotate(stack_a, NULL, 0);
			count_rotate_a++;

    }
    if (!b_merge && stack_b && stack_b->head->next) {
      ft_rotate(NULL, stack_b, 1);
			count_rotate_b++;
    }

    if ( !a_merge && stack_a && count_rotate_a == stack_a->lenght - 1)
    {
        ft_rotate(stack_a, NULL, 0);
        count_rotate_a = 0;
    }
    if ( !b_merge && stack_b && count_rotate_b == stack_b->lenght - 1)
    {
      ft_rotate(NULL,stack_b , 1);
      count_rotate_b = 0;
    }*/
	}
}

/*Recursivly sort stack_a and stack_b*/
void 			divide_algo(t_dllist *stack_a, int maxLenghtNb)
{
	t_dllist	*stack_b;

	stack_b = NULL;
  view_stack(stack_a, stack_b, 42);
	if (stack_a->lenght)
	{
		 stack_b = divide_stack(stack_a, stack_a->lenght / 2);
	}
	merge_stack_brut(stack_a, stack_b);
  fusion_merge(stack_a, stack_b);
	ft_putchar('\n');
  view_stack(stack_a, stack_b, 42);

}
