#include "libft.h"

void	darr_insert(t_darr *darr, size_t index, void *data)
{
	void	*src;
	void	*dst;

	if (darr && index <= darr->size)
	{
		if (darr->size == darr->capacity)
			darr_resize(darr, (size_t)((double)darr->capacity * 1.5));
		src = (void*)darr->data + darr->data_type_size * index;
		dst = src + darr->data_type_size;
		if (index < darr->size)
			ft_memmove(dst, src, darr->data_type_size * (darr->size - index));
		if (data)
			ft_memcpy(src, data, darr->data_type_size);
		else
			ft_bzero(src, darr->data_type_size);
		darr->size++;
	}
}
