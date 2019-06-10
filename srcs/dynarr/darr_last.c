#include "libft.h"

void	*darr_last(t_darr *darr)
{
	void	*result;

	result = NULL;
	if (darr)
	{
		result = darr_at(darr, darr->size - 1);
	}
	return (result);
}