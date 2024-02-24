/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:19:40 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/24 02:09:39 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    *set_window(void *mlx, t_map map)
{
    void    *win;

    win = mlx_new_window(mlx, map.x * 64, map.y * 64, "so_long");
    if (!win)
        exit(EXIT_FAILURE);
    return (win);
}

void	set_map(t_data *data)
{
	int i;
	int j;
	char **map;

	i = 0;
	map = data->map;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			set_texture(data, map[i][j], (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

void	set_texture(t_data *data, char c, int x, int y)
{
	void	*img;
	int		height;
	int		width;
	
	if (c == '0')
	{
		// img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[0], &width, &height);
		// if(!img)
		// 	exit(EXIT_FAILURE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, x, y);
	}
	else if (c == '1')
	{
		img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[1], &width, &height);
		if(!img)
			exit(EXIT_FAILURE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x, y);
	}
	else if (c == 'C')
	{
		img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[2], &width, &height);
		if(!img)
			exit(EXIT_FAILURE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x, y);
	}
	else if (c == 'E')
	{
		img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[3], &width, &height);
		if(!img)
			exit(EXIT_FAILURE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x, y);
	}
	else if (c == 'P')
	{
		img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[0], &width, &height);
		if(!img)
			exit(EXIT_FAILURE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x, y);
		img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[4], &width, &height);
		if(!img)
			exit(EXIT_FAILURE);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, x, y);
	}
}
