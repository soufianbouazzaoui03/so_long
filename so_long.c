/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:12:29 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/07 22:20:56 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exitwindow(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'X')
			{
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
				free_all(data);
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	set_img_ptr(t_data *data)
{
	int	w;
	int	h;

	data->img_ptr[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"man_img/Green.xpm", &w, &h);
	data->img_ptr[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"man_img/bg1.xpm", &w, &h);
	data->img_ptr[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"man_img/gold/1.xpm", &w, &h);
	data->img_ptr[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"man_img/player/1.xpm", &w, &h);
	data->img_ptr[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"man_img/player/leftbg.xpm", &w, &h);
	data->img_ptr[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"man_img/water/1.xpm", &w, &h);
	data->player = 3;
	check_ptr_imgs(data, 1);
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_all(data);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		check_argv(argv[1]);
		data.mlx_ptr = mlx_init();
		if (!data.mlx_ptr)
		{
			ft_putstr_fd("Error\nMLX_ERROR\n", 2);
			exit(EXIT_FAILURE);
		}
		data.map = get_map(argv[1]);
		data.win_ptr = set_window(data.mlx_ptr, map_demontion(&data), &data);
		set_img_ptr(&data);
		set_map(&data);
		mlx_hook(data.win_ptr, 2, 0, ft_close, &data);
		mlx_hook(data.win_ptr, 17, 0, close_win, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
	{
		ft_putstr_fd("Error\nINVALID ARGS!\n", 2);
		exit(1);
	}
	return (0);
}
