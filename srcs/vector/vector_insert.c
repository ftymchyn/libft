#include "libft.h"

void	vector_insert(t_vector *vec, size_t index, void *data)
{
	void	*src;
	void	*dst;
	size_t	vsize;

	if (vec && data)
	{
		vsize = vector_size(vec);
		if (index <= vsize)
		{
			if (vsize == vec->capacity)
				vector_resize(vec, vec->capacity + 10);
			src = (void*)vec->data + vec->data_type_size * index;
			dst = (void*)vec->data + vec->data_type_size * (index + 1);
			ft_memmove(dst, src, vec->data_type_size * (vsize - index));
			ft_memcpy(src, data, vec->data_type_size);
			vec->index_to_last++;
		}
	}
}
