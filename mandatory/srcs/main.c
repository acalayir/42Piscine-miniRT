
#include "../incs/defines.h"
#include "../incs/parsing.h"
#include "../incs/three_value.h"
#include "../incs/utils.h"
#include "../incs/viewer.h"
#include "../incs/mlx_rt.h"

void	init_d(t_data *d)
{
	d->object = NULL;
	d->parsed.ambient = 0;
	d->parsed.camera = 0;
	d->parsed.light = 0;
}

int	main(int ac, char **av)
{
	t_data	d;
	t_mlx	mlx;

	init_d(&d);
	map_parsing(ac, av, &d);
	make_viewer(&d);
	mlx.mlx = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx, WIN_WIDTH, WIN_HEIGHT, "miniRT");
	mlx.img = mlx_new_image(mlx.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx.addr = mlx_get_data_addr
		(mlx.img, &mlx.bits_per_pixel, &mlx.line_length, &mlx.endian);
	make_mlx_img(&d, &mlx);
	mlx.data = &d;
	mlx_put_image_to_window(mlx.mlx, mlx.mlx_win, mlx.img, 0, 0);
	mlx_key_hook(mlx.mlx_win, key_hook, &mlx);
	mlx_hook(mlx.mlx_win, 17, 0, ft_click, &mlx);
	mlx_loop(mlx.mlx);
	free_d(&d);
	return (0);
}
