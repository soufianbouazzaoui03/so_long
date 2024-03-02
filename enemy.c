/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:06:22 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/02 18:45:32 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	check_imgs(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while(i < 5)
// 	{
// 		if(!data->enemy_img[0])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// void	set_enemy_imgs(t_data *data)
// {
// 	int h;
// 	int w;
	
// 	data->enemy_img[0] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/1.xpm", &w, &h);
// 	data->enemy_img[1] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/2.xpm", &w, &h);
// 	data->enemy_img[2] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/3.xpm", &w, &h);
// 	data->enemy_img[3] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/4.xpm", &w, &h);
// 	data->enemy_img[4] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/5.xpm", &w, &h);
// 	data->enemy_img[5] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/6.xpm", &w, &h);
// 	data->enemy_img[6] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/7.xpm", &w, &h);
// 	data->enemy_img[7] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/8.xpm", &w, &h);
// 	data->enemy_img[8] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/9.xpm", &w, &h);
// 	data->enemy_img[9] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/10.xpm", &w, &h);
// 	data->enemy_img[10] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/11.xpm", &w, &h);
// 	data->enemy_img[11] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/12.xpm", &w, &h);
// 	data->enemy = 0;
// }

int	enemy_moves(t_data *data)
{
	static int move;
	int i;
	int j;
	int check = 0;

	i = 0;
	if(move == 4000)
	{
		check = 0;
		while(data->map[i] && (check == 0))
		{
			j = 0;
			while(data->map[i][j])
			{
				if(data->map[i][j] == 'N')
				{
					if(move_D(data, i, j) == 1)
						break ;
					else if(move_S(data, i, j) == 1)
						check++;
					else if(move_W(data, i, j) == 1)
						break ;
					else if(move_A(data, i, j) == 1)
						break ;
					else
						return(0);
				}
				j++;
			}
			i++;
		}
		move = 0;
	}
	move++;
	return (0);
}



