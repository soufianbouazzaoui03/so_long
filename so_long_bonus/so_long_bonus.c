/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:12:29 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/07 22:24:03 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	set_text(t_data *data)
{
	data->player = 3;
	data->gate = 0;
	data->gold = 0;
	data->moves = 0;
	data->moves_string = ft_itoa(0);
}

void	set_gate_img(t_data *data)
{
	int	w;
	int	h;

	data->gate_img[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/water/1.xpm", &w, &h);
	data->gate_img[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/water/2.xpm", &w, &h);
	data->gate_img[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/water/3.xpm", &w, &h);
	data->gate_img[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/water/4.xpm", &w, &h);
	data->gate_img[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/water/5.xpm", &w, &h);
	data->gate_img[5] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/water/6.xpm", &w, &h);
	data->gate_img[6] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/water/7.xpm", &w, &h);
	data->gate_img[7] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/water/8.xpm", &w, &h);
	data->gate_img[8] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/water/9.xpm", &w, &h);
	check_gate_imgs(data, 1);
}

void	set_img_ptr(t_data *data)
{
	int	w;
	int	h;

	set_text(data);
	set_gold_imgs(data);
	data->img_ptr[0] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/Green.xpm", &w, &h);
	data->img_ptr[1] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/bg1.xpm", &w, &h);
	data->img_ptr[2] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/monster/1.xpm", &w, &h);
	data->img_ptr[3] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/player/1.xpm", &w, &h);
	data->img_ptr[4] = mlx_xpm_file_to_image(data->mlx_ptr,
			"b_img/player/leftbg.xpm", &w, &h);
	check_ptr_imgs(data, 1);
	set_gate_img(data);
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
		mlx_loop_hook(data.mlx_ptr, ft_anime, &data);
		mlx_loop(data.mlx_ptr);
	}
	else
		return (ft_putstr_fd("Error\nINVALID ARGS!\n", 2), 1);
	return (0);
}
