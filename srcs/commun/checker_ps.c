#include "../../includes/push_swap.h"

t_dllist		*validate_and_stacka(char **av, int ac)
{
	t_dllist	*stack;
	char		*ptr;
	int			cod;
	int			i;

	i = 0;
	stack = NULL;
	while (i < ac)
	{
		if ((cod = control(av[i], &stack)) < 0)
			return (error_gest(&stack, cod));
		ft_lstadd(&stack, ft_lstnew(ft_atoi(av[i]), sizeof(int)));
		i++;
	}
	return (stack);
}
