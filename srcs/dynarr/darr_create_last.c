#include "libft.h"

void	*darr_create_last(t_darr *darr)
{
	void	*result;

	result = NULL;
	if (darr)
	{
		darr_pushback(darr, NULL);
		result = darr_last(darr);
	}
	return (result);
}