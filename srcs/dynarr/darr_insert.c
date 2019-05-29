#include "libft.h"

void	darr_insert(t_darr *darr, size_t index, void *data)
{
	void	*src;
	void	*dst;
	size_t	vsize;

	if (darr && data)
	{
		vsize = darr_size(darr);
		if (index <= vsize)
		{
			if (vsize == darr->capacity)
				darr_resize(darr, darr->capacity + 10);
			src = (void*)darr->data + darr->data_type_size * index;
			dst = (void*)darr->data + darr->data_type_size * (index + 1);
			ft_memmove(dst, src, darr->data_type_size * (vsize - index));
			ft_memcpy(src, data, darr->data_type_size);
			darr->index_to_last++;
		}
	}
}
