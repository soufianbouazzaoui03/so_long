/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:12:29 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/24 02:10:33 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_close(int key, t_data *data)
{
    if (key == 53)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    if(key == 2)
    {
        handlemoves(data->map, 'D');
        set_map(data);
    }
    if(key == 0)
    {
        handlemoves(data->map, 'A');
        set_map(data);
    }
    if(key == 13)
    {
        handlemoves(data->map, 'W');
        set_map(data);
    }
    if(key == 1)
    {
        handlemoves(data->map, 'S');
        set_map(data);
    }
    usleep(100);
	return (0);
}

int main()
{
    t_data  data;
    int w;
    int h;

    //data = malloc(sizeof(t_data));
    // if(!data)
    //     exit(EXIT_FAILURE);
    data.map = get_map("maps.txt");
    if(!data.map)
        exit(EXIT_FAILURE);
    data.mlx_ptr = mlx_init();
    data.win_ptr = set_window(data.mlx_ptr, map_demontion("maps.txt"));
    data.textures[0] = "Green.xpm";
    data.textures[1] = "Gray.xpm";
    data.textures[2] = "Yellow.xpm";
    data.textures[4] = "charachter.xpm";
    data.textures[3] = "Pink.xpm";
    data.img_ptr = mlx_xpm_file_to_image(data.mlx_ptr, data.textures[0], &w,&h);
    set_map(&data);
    mlx_hook(data.win_ptr,2,0,ft_close, &data);
    mlx_loop(data.mlx_ptr);
}