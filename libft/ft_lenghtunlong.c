#include "Includes/libft.h"

int			ft_lenghtunlong(unsigned long long ll)
{
	size_t	ret;

	ret = 1;
	while ((ll /= 10) > 0)
		ret++;
	return (ret);
}