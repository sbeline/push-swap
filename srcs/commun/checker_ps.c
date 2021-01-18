#include "../../includes/push_swap.h"

static int	nblen(int n)
{
	if (n < 0)
		return (1 + nblen(-n));
	if (n < 10)
		return (1);
	return (1 + nblen(n / 10));
}

t_dllist		*validate_and_stacka(char **av, int ac, int *maxLenghtNb)
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
		if (*maxLenghtNb < ft_atoi(av[i]))
			*maxLenghtNb = nblen(ft_atoi(av[i]));
		ft_lstadd(&stack, ft_lstnew(ft_atoi(av[i]), sizeof(int)));
		i++;
	}
	return (stack);
}
