#include "libft.h"

void	vector_pushback(t_vector *vec, void *data)
{
	if (vec)
	{
		vector_insert(vec, vec->index_to_last, data);
	}
}
