#include "libft.h"

void	vector_foreach(t_vector *vec, void (*applyf)(void*))
{
	size_t i;

	if (applyf)
	{
		i = 0;
		while (i < vector_size(vec))
		{
			(*applyf)(vector_at(vec, i));
			i++;
		}
	}
}
