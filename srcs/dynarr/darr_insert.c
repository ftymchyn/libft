#include "libft.h"

void	darr_insert(t_darr *darr, size_t index, void *data)
{
	void	*src;
	void	*dst;

	if (darr && data)
	{
		if (index <= darr->size)
		{
			if (darr->size == darr->capacity)
				darr_resize(darr, (size_t)((double)darr->capacity * 1.5));
			src = (void*)darr->data + darr->data_type_size * index;
			dst = src + darr->data_type_size;
			ft_memmove(dst, src, darr->data_type_size * (darr->size - index));
			ft_memcpy(src, data, darr->data_type_size);
			darr->size++;
		}
	}
}
