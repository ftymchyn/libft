#include "libft.h"

void	darr_erase(t_darr *darr, size_t index, void *return_data)
{
	void	*src;
	void	*dst;
	size_t	vsize;
	
	vsize = darr_size(darr);
	if (index < vsize)
	{
		dst = darr_at(darr, index);
		src = dst + darr->data_type_size;
		if (return_data)
			ft_memcpy(return_data, dst, darr->data_type_size);
		if ( index != (vsize - 1))
			ft_memcpy(dst, src, darr->data_type_size * (vsize - index - 1));
		darr->index_to_last--;
	}
}
