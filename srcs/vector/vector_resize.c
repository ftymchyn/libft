#include "libft.h"

void	vector_resize(t_vector *vec, size_t new_size)
{
	void	*ndata;
	size_t	dsize;
	size_t	vsize;

	if (vec && vec->capacity != new_size)
	{
		dsize = vec->data_type_size;
		vsize = vector_size(vec);
		if (new_size < vsize)
			new_size = vsize;
		ndata = ft_memalloc(dsize * new_size);
		if (ndata)
		{
			if (vec->data)
			{
				ft_memcpy(ndata, (void*)vec->data, dsize * vsize);
				ft_memdel((void**)&vec->data);
			}
			vec->data = (unsigned char*)ndata;
			vec->capacity = new_size;
		}
	}
}
