#include "frl.h"
#include "../mlx_linux/mlx.h"
#include "stdlib.h"

int		frl_int_clean(t_vars **vars)
{
	*(*vars)->window_count = *(*vars)->window_count - 1;
	mlx_destroy_image((*vars)->mlx, (*vars)->data->img);
	mlx_destroy_window((*vars)->mlx, (*vars)->win);
	ft_memdel((void**)&(*vars)->set);
	ft_memdel((void**)&(*vars)->data);
	if (*(*vars)->window_count == 0)
	{
		mlx_destroy_display((*vars)->mlx);
		ft_memdel((void**)&(*vars)->mlx);
		free((*vars)->arr);
		ft_memdel((void**)&(*vars));
		exit(0);
	}
	ft_memdel((void**)&(*vars));
	return (0);
}
