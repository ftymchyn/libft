#include "libft.h"

void	darr_init(t_darr *darr, int data_type_size)
{
	if (darr)
	{
		ft_bzero(darr, sizeof(t_darr));
		darr->data_type_size = data_type_size;
		darr_resize(darr, 10);
	}
}