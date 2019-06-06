#include "libft.h"

void	darr_foreach(t_darr *darr, void (*applyf)(void*))
{
	size_t i;

	if (darr && applyf)
	{
		i = 0;
		while (i < darr->size)
		{
			(*applyf)(darr_at(darr, i));
			i++;
		}
	}
}
