#include "libft.h"

void	vector_erase(t_vector *vec, size_t index, void *return_data)
{
	void	*src;
	void	*dst;
	size_t	vsize;
	
	vsize = vector_size(vec);
	if (index < vsize)
	{
		dst = vector_at(vec, index);
		src = dst + vec->data_type_size;
		if (return_data)
			ft_memcpy(return_data, dst, vec->data_type_size);
		if ( index != (vsize - 1))
			ft_memcpy(dst, src, vec->data_type_size * (vsize - index - 1));
		vec->index_to_last--;
	}
}
