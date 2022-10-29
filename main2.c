#include <mlx.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	int i	;

// 	i = 150;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1920, 1080);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	while (i < 1920 - 250)
// 	{
// 		my_mlx_pixel_put(&img, i, 150, 0x0000FFFF);
// 		i++;
// 	}
// 	i = 150;
// 	while (i < 1920 - 250)
// 	{
// 		my_mlx_pixel_put(&img, i, 1080 - 250, 0x0000FFFF);
// 		i++;
// 	}
// 	i = 150;
// 	while (i < 1080 - 250)
// 	{
// 		my_mlx_pixel_put(&img, 150, i, 0x0000FF00);
// 		i++;
// 	}
// 	i = 150;
// 	while (i < 1080 - 250)
// 	{
// 		my_mlx_pixel_put(&img, 1920 - 250, i, 0x00FF0000);
// 		i++;
// 	}
// 	// while (i < 1080)
// 	// {
// 	// 	my_mlx_pixel_put(&img, 150, i, 0x0000FFFF);
// 	// 	i++;
// 	// }
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	printf("Hello from key_hook!\n");
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	// mlx_mouse_hook(vars.win, mouse_hook, &vars);
	// mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}