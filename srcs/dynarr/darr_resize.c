#include "libft.h"

void	darr_resize(t_darr *darr, int new_size)
{
	void	*ndata;
	int		dsize;

	if (darr && darr->capacity != new_size)
	{
		dsize = darr->data_type_size;
		if (new_size < darr->size)
			new_size = darr->size;
		ndata = ft_memalloc(dsize * new_size);
		if (ndata)
		{
			if (darr->data)
			{
				ft_memcpy(ndata, (void*)darr->data, dsize *  darr->size);
				ft_memdel((void**)&darr->data);
			}
			darr->data = (unsigned char*)ndata;
			darr->capacity = new_size;
		}
	}
}
