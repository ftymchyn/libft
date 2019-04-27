#include "libft.h"

void	*vector_at(t_vector *vec, size_t index)
{
	void	*result;
	size_t	data_offset;

	result = NULL;
	if (index < vector_size(vec))
	{
		data_offset = vec->data_type_size * index;
		result = (void*)vec->data + data_offset;
	}
	return (result);
}
