/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:19:40 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/12 22:36:38 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*map_demontion(int fd)
{
	t_map	*demontion = malloc(sizeof(t_map));
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	demontion->x = ft_strlen(line) - 1;
	demontion->y = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		demontion->y++;
		free(line);
	}
	return (demontion);
}

void    *set_window(void *mlx, t_map *map)
{
    void    *win;

    win = mlx_new_window(mlx, map->x * 64, map->y * 64, "so_long");
    if (!win)
        return (NULL) ;
    return (win);
}

void	set_map(t_data *data, int fd)
{
	char	*line;
	int		i;
	int		x;
	int		y;

	y = 0;
	while(1)
	{
		x = 0;
		i = 0;
		line = get_next_line(fd);
		if(!line)
			break ;
		while(line[i] != '\0')
		{
			set_texture(data, line[i], &x, &y);
			x += 64;
			i++;
		}
		y += 64;
	}
}

void	set_texture(t_data *data, char c, int *x, int *y)
{
	void	*img;
	int		height;
	int		width;
	
	if (c == '0')
	{
		img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[0], &width, &height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, *x, *y);
	}
	else if (c == '1')
	{
		img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[1], &width, &height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, *x, *y);
	}
	else if (c == 'c')
	{
		img = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[2], &width, &height);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, *x, *y);
	}
}
