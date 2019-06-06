#include "libft.h"

void	darr_pushback(t_darr *darr, void *data)
{
	if (darr)
	{
		darr_insert(darr, darr->size, data);
	}
}
