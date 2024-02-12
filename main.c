#include <mlx.h>
#include <stdio.h>

typedef struct s_data {

	void	*mlx;
	void	*win;
}	t_data;


int	key_hook(int keycode, t_data *vars)
{
	
	printf("%d\n", keycode);
	printf("Hello from key_hook!\n");
	return (0);
}

void	put_bg(void *img, void *window, void *mlx, int *width, int	*heigh)
{
	int x = 0;
	int y = 0;
	int i;

	while(x < 640)
	{
		mlx_put_image_to_window(mlx, window, img, x, y);
		x += *width;
	}
}

int	main(void)
{
	void	*mlx;
	void	*img;
	void	*window;
	char	*relative_path = "./Green.xpm";
	int		img_width;
	int		img_height;
	int x = 0;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
	window = mlx_new_window(mlx, 640, 1080, "so_long");

	// while(x <= 640)
	// {
	// 	printf("%d\n", x);
	// 	mlx_put_image_to_window(mlx, window, img, x, 0);
	// 	x += img_width;
	// }


	put_bg(img, window, mlx, &img_width, &img_height);
	mlx_key_hook(window, key_hook, mlx);
	mlx_loop(mlx);
}