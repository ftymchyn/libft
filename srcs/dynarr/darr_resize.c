#include "libft.h"

void	darr_resize(t_darr *darr, size_t new_size)
{
	void	*ndata;
	size_t	dsize;
	size_t	arrsize;

	if (darr && darr->capacity != new_size)
	{
		dsize = darr->data_type_size;
		arrsize = darr_size(darr);
		if (new_size < arrsize)
			new_size = arrsize;
		ndata = ft_memalloc(dsize * new_size);
		if (ndata)
		{
			if (darr->data)
			{
				ft_memcpy(ndata, (void*)darr->data, dsize * arrsize);
				ft_memdel((void**)&darr->data);
			}
			darr->data = (unsigned char*)ndata;
			darr->capacity = new_size;
		}
	}
}
