/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:12:29 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/27 02:40:35 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exitwindow(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map[i])
    {
        j = 0;
        while (data->map[i][j])
        {
            if (data->map[i][j] == 'X')
            {
                mlx_destroy_window(data->mlx_ptr, data->win_ptr);
                exit(0);
            }
            j++;
        }
        i++;
    }
}

void moveshandler(t_data *data, char move)
{
    handlemoves(data->map, move);
    if (move == 'A')
    {
        data->player = 5;
        set_map(data);
    }
    if (move == 'D')
    {
        data->player = 4;
        set_map(data);
    }
    else
        set_map(data);
}


int ft_anime(t_data *data)
{
    ft_anime_gate(data);
    ft_anime_gold(data);
    return (0);
}


int ft_close(int key, t_data *data)
{
    if (key == 53)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(0);
    }
    if (key == 2)
        moveshandler(data, 'D');
    if (key == 0)
        moveshandler(data, 'A');
    if (key == 13)
        moveshandler(data, 'W');
    if (key == 1)
        moveshandler(data, 'S');
    exitwindow(data);
    return (0);
}

void    set_text(t_data *data)
{
    data->textures[0] = "Green.xpm";
    data->textures[1] = "Gray.xpm";
    data->textures[2] = "gold/1.xpm";
    data->textures[4] = "player/1.xpm";
    data->textures[3] = "gate.xpm";
    data->textures[5] = "player/leftbg.xpm";
}

void set_img_ptr(t_data *data)
{
    int w;
    int h;

    set_text(data);
    data->img_ptr[0] = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[0], &w, &h);
    data->img_ptr[1] = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[1], &w, &h);
    data->img_ptr[2] = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[2], &w, &h);
    data->img_ptr[3] = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[3], &w, &h);
    data->img_ptr[4] = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[4], &w, &h);
    data->img_ptr[5] = mlx_xpm_file_to_image(data->mlx_ptr, data->textures[5], &w, &h);
    data->gate_img[0] = mlx_xpm_file_to_image(data->mlx_ptr, "water/1.xpm", &w, &h);
    data->gate_img[1] = mlx_xpm_file_to_image(data->mlx_ptr, "water/2.xpm", &w, &h);
    data->gate_img[2] = mlx_xpm_file_to_image(data->mlx_ptr, "water/3.xpm", &w, &h);
    data->gate_img[3] = mlx_xpm_file_to_image(data->mlx_ptr, "water/4.xpm", &w, &h);
    data->gate_img[4] = mlx_xpm_file_to_image(data->mlx_ptr, "water/5.xpm", &w, &h);
    data->gate_img[5] = mlx_xpm_file_to_image(data->mlx_ptr, "water/6.xpm", &w, &h);
    data->gate_img[6] = mlx_xpm_file_to_image(data->mlx_ptr, "water/7.xpm", &w, &h);
    data->gate_img[7] = mlx_xpm_file_to_image(data->mlx_ptr, "water/8.xpm", &w, &h);
    data->gate_img[8] = mlx_xpm_file_to_image(data->mlx_ptr, "water/9.xpm", &w, &h);
    data->player = 4;
    data->gate = 0;
    data->gold = 0;
}

int main()
{
    t_data data;

    data.map = get_map("maps.txt");
    if (!data.map)
        exit(EXIT_FAILURE);
    data.mlx_ptr = mlx_init();
    data.win_ptr = set_window(data.mlx_ptr, map_demontion("maps.txt"));
    set_img_ptr(&data);
    set_gold_imgs(&data);
    checkimgs(&data);
    set_map(&data);
    mlx_hook(data.win_ptr, 2, 0, ft_close, &data);
    mlx_loop_hook(data.mlx_ptr, ft_anime, &data);
    mlx_loop(data.mlx_ptr);
    return (0);
}
