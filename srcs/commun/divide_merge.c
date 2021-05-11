#include "../../includes/push_swap.h"

static t_dllist	*divide_stack(t_dllist *stack_a, int midLenghtStack)
{
	t_dllist *stack_b;
	int count;

	count = 0;
	stack_b = NULL;
	while (count != midLenghtStack)
	{
		push(&stack_a, &stack_b);
		count++;
	}
	return (stack_b);
}

static void fusion_merge(t_dllist *stack_a, t_dllist *stack_b)
{
  int count;

  count = 0;
  while ((stack_is_merge(stack_a) || stack_b) && count < stack_a->lenght)
  {
    if (stack_b && stack_b->head->content < stack_a->head->content)
      push(&stack_b, &stack_a);
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

static void double_merge(t_dllist *stack_a, t_dllist *stack_b)
{
	int a_merge;
	int b_merge;
  int count_rotate;

	a_merge = 0;
	b_merge = 0;
  count_rotate = 0;
	while (!a_merge || !b_merge)
	{
    if (!a_merge && stack_a->head->next &&
       stack_a->head->content > stack_a->head->next->content) {
      swap(stack_a, NULL, 0);
    }
    if (!b_merge && stack_b->head->next &&
       stack_b->head->content > stack_b->head->next->content) {
      swap(stack_b, NULL, 0);
    }
    if (!a_merge && stack_a->head->next){
      ft_rotate(stack_a, NULL, 0);
    }
    if (!b_merge && stack_b->head->next) {
      ft_rotate(stack_b, NULL, 0);
    }
    count_rotate++;
    if ( !a_merge && count_rotate == stack_a->lenght - 1)
    {
        ft_rotate(stack_a, NULL, 0);
        count_rotate = 0;
    }
    if ( !b_merge && count_rotate == stack_b->lenght - 1)
    {
      ft_rotate(stack_b, NULL, 0);
      count_rotate = 0;
    }
		a_merge = stack_is_merge(stack_a);
		b_merge = stack_is_merge(stack_b);
    /*printf("count_rotate{%d}, stack_a->lenght[%d]\n", count_rotate, stack_a->lenght);
    printf("count_rotate{%d}, stack_b->lenght[%d]\n", count_rotate, stack_b->lenght);
    printf("a_merge{%d}, b_merge[%d]\n", a_merge, 	b_merge);
    ft_putstr("--------------------------------------\n");*/
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
	double_merge(stack_a, stack_b);
  fusion_merge(stack_a, stack_b);
  view_stack(stack_a, stack_b, 42);

}
