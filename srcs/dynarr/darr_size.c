#include "libft.h"

size_t	darr_size(t_darr *darr)
{
	size_t result;

	result = 0;
	if (darr)
	{
		result = darr->index_to_last;
	}
	return (result);
}