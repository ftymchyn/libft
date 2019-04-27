#include "libft.h"

t_vector	*vector_create(size_t data_type_size)
{
	t_vector	*result;

	result = (t_vector*)ft_memalloc(sizeof(t_vector));
	if (result)
	{
		result->data_type_size = data_type_size;
		vector_resize(result, 10);
		if (!result->data)
		{
			vector_clear(&result, NULL);
		}
	}
	return (result);
}