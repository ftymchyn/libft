#include "libft.h"

void	*darr_at(t_darr *darr, int index)
{
	void	*result;
	int		data_offset;

	result = NULL;
	if (darr && index < darr->size)
	{
		data_offset = darr->data_type_size * index;
		result = (void*)darr->data + data_offset;
	}
	return (result);
}
