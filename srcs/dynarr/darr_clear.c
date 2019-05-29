#include "libft.h"

void	darr_clear(t_darr *darr, void (*destructf)(void*))
{
	if (darr)
	{
		if (destructf)
			darr_foreach(darr, destructf);
		free(darr->data);
		ft_bzero(darr, sizeof(t_darr));
	}
}