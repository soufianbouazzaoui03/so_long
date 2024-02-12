/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:12:29 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/12 22:46:32 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main()
{
    t_map   *demo;
    t_data  *data;
    int     fd;
    
    data = malloc(sizeof(t_data));
    fd = open("maps.txt", O_RDONLY);
    demo = map_demontion(fd);
    data->map = demo;
    data->mlx_ptr = mlx_init();
    data->win_ptr = set_window(data->mlx_ptr, data->map);
    data->textures[0] = "Green.xpm";
    data->textures[1] = "Gray.xpm";
    data->textures[2] = "Yellow.xpm";
    lseek(fd, 0, SEEK_SET);
    set_map(data, fd);
    mlx_loop(data->mlx_ptr);
}