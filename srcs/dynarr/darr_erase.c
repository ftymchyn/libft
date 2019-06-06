#include "libft.h"

void	darr_erase(t_darr *darr, size_t index, void *return_data)
{
	void	*src;
	void	*dst;
	
	if (darr && index < darr->size)
	{
		dst = darr_at(darr, index);
		src = dst + darr->data_type_size;
		if (return_data)
			ft_memcpy(return_data, dst, darr->data_type_size);
		if (index != (darr->size - 1))
			ft_memcpy(dst, src, darr->data_type_size * (darr->size - index - 1));
		darr->size--;
	}
}
