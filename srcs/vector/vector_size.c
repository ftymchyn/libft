#include "libft.h"

size_t	vector_size(t_vector *vec)
{
	size_t result;

	result = 0;
	if (vec)
	{
		result = vec->index_to_last;
	}
	return (result);
}