#include "libft.h"

void	*darr_at(t_darr *darr, size_t index)
{
	void	*result;
	size_t	data_offset;

	result = NULL;
	if (index < darr_size(darr))
	{
		data_offset = darr->data_type_size * index;
		result = (void*)darr->data + data_offset;
	}
	return (result);
}
