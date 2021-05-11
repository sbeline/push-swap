#include "../../includes/push_swap.h"

static void aff_stack_title(int maxLenghtNb)
{
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	ft_putchar('a');
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	ft_putchar('|');
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	ft_putchar('b');
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	ft_putchar('\n');
	ft_printmuliplecar(maxLenghtNb * 2 + 1, '_');
	ft_putchar('\n');
}

static void placement_print(char *stackName, int maxLenghtNb, int opt)
{
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	ft_putstr(stackName);
	maxLenghtNb -= (maxLenghtNb % 2 != 0) ? 0 : 1;
	ft_printmuliplecar(maxLenghtNb / 2, ' ');
	if (opt) {
		ft_putchar('|');
	}
}

void listA_is_supp(int maxLenghtNb, t_dllist *a, t_dllist *b)
{
	t_llist *lst_a;
	t_llist *lst_b;
	int lenghtA;
	int lenghtB;

	lenghtA =  (a) ? a->lenght : 0;
	lenghtB =  (b) ? b->lenght : 0;
	if (a && a->head)
	{
		lst_a = (lenghtA) ? a->head : NULL;
		lst_b = lst_b = (lenghtB) ? b->head : NULL;
		//printf("print a lenghtA[%d]; lenghtB[%d]\n", lenghtA, lenghtB);
		while (lst_a)
		{
			placement_print(ft_itoa(lst_a->content), maxLenghtNb -
												ft_nblen(lst_a->content), 1);
			//printf("smallest[%d]\n", lst_a->smallest);
			lst_a = lst_a->next;
			if (lst_b)
			{
				placement_print(ft_itoa(lst_b->content), maxLenghtNb -
													ft_nblen(lst_b->content), 0);
				//printf("smallest[%d]\n", lst_a->smallest);
				lst_b = lst_b->next;
			}
			ft_putchar('\n');
		}
	}
}
void listB_is_supp(int maxLenghtNb, t_dllist *a, t_dllist *b)
{
	t_llist *lst_a;
	t_llist *lst_b;
	int lenghtA;
	int lenghtB;

	lenghtA =  (a) ? a->lenght : 0;
	lenghtB =  (b) ? b->lenght : 0;
	if (b && b->head)
	{
		lst_a = (lenghtA) ? a->head : NULL;
		lst_b = lst_b = (lenghtB) ? b->head : NULL;
	//	printf(" print b lenghtA[%d]; lenghtB[%d]\n", lenghtA, lenghtB);
		while (lst_b)
		{
			if (lst_a)
			{
				placement_print(ft_itoa(lst_a->content), maxLenghtNb -
													ft_nblen(lst_a->content), 1);
				//printf("smallest[%d]\n", lst_a->smallest);
				lst_a = lst_a->next;
			} else {
				placement_print(" ", maxLenghtNb - 1, 1);
			}
			placement_print(ft_itoa(lst_b->content), maxLenghtNb -
											ft_nblen(lst_b->content), 0);
			//printf("smallest[%d]\n", lst_a->smallest);
			lst_b = lst_b->next;
			ft_putchar('\n');
		}
	}
}

void view_stack(t_dllist *a, t_dllist *b, int maxLenghtNb)
{
	int lenghtA;
	int lenghtB;

	maxLenghtNb += (maxLenghtNb % 2 == 0) ? 0 : 1;
	lenghtA =  (a) ? a->lenght : 0;
	lenghtB =  (b) ? b->lenght : 0;
	aff_stack_title(maxLenghtNb - 1);
	if (lenghtA || 	lenghtB)
	{
		if (lenghtA >= lenghtB) {
			listA_is_supp(maxLenghtNb, a, b);
		} else {
			listB_is_supp(maxLenghtNb, a, b);
		}

	}
}
