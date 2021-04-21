#include "Includes/libft.h"

int	ft_nblen(int n)
{
	if (n < 0)
		return (1 + ft_nblen(-n));
	if (n < 10)
		return (1);
	return (1 + ft_nblen(n / 10));
}
