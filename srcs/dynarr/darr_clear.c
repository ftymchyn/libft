#include "libft.h"

void	vector_clear(t_vector **vec, void (*destructf)(void*))
{
	if (vec && *vec)
	{
		if (destructf)
			vector_foreach(*vec, destructf);
		ft_memdel((void**)&((*vec)->data));
		ft_memdel((void**)vec);
	}
}