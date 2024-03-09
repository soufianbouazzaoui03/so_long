/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:19:40 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/04 21:41:57 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*set_window(void *mlx, t_map map, t_data *data)
{
	void	*win;

	win = mlx_new_window(mlx, map.x * 64, (map.y) * 64, "so_long");
	if (!win)
	{
		freemap(data->map);
		ft_putstr_fd("ERROR CREATING THE WINDOW", 2);
		exit(EXIT_FAILURE);
	}
	return (win);
}

void	set_map(t_data *data)
{
	int		i;
	int		j;
	char	**map;

	i = 0;
	map = data->map;
	mlx_clear_window(data->map, data->win_ptr);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			set_texture(data, map[i][j], (j * 64), (i * 64));
			j++;
		}
		i++;
	}
}

void	set_texture_2(t_data *data, char c, int x, int y)
{
	if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr[0], x, y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr[data->player], x, y);
	}
}

void	set_texture(t_data *data, char c, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr[0], x, y);
	else if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr[1], x, y);
	else if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr[0], x, y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr[2], x, y);
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr[0], x, y);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->img_ptr[5], x, y);
	}
	set_texture_2(data, c, x, y);
}
