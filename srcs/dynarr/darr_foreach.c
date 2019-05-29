#include "libft.h"

void	darr_foreach(t_darr *darr, void (*applyf)(void*))
{
	size_t i;

	if (applyf)
	{
		i = 0;
		while (i < darr_size(darr))
		{
			(*applyf)(darr_at(darr, i));
			i++;
		}
	}
}
