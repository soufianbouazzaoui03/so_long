/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:12:29 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/02 21:38:56 by soel-bou         ###   ########.fr       */
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
                free_all(data);
                exit(0);
            }
            j++;
        }
        i++;
    }
}

void moveshandler(t_data *data, char move)
{
    data->moves++;
    handlemoves(data->map, move);
    if (move == 'A')
    {
        data->player = 4;
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        set_map(data);
    }
    if (move == 'D')
    {
        data->player = 3;
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        set_map(data);
    }
    else
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        set_map(data);
    }
}


int ft_anime(t_data *data)
{
    ft_anime_gate(data);
    ft_anime_gold(data);
    //ft_anime_enemy(data);
    enemy_moves(data);
    return (0);
}


int ft_close(int key, t_data *data)
{
    if (key == 53)
    {
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        //free_all(data);
        free(data->mlx_ptr);
        exit(0);
    }
    if (key == 2 || key == 124)
        moveshandler(data, 'D');
    if (key == 0 || key == 123)
        moveshandler(data, 'A');
    if (key == 13 || key == 126)
        moveshandler(data, 'W');
    if (key == 1 || key == 125)
        moveshandler(data, 'S');
    exitwindow(data);
    return (0);
}

void    set_text(t_data *data)
{
    data->player = 3;
    data->gate = 0;
    data->gold = 0;
    data->moves = 0;
    data->moves_string = ft_itoa(0);
}

void set_img_ptr(t_data *data)
{
    int w;
    int h;

    set_text(data);
    set_gold_imgs(data);
    data->img_ptr[0] = mlx_xpm_file_to_image(data->mlx_ptr, "Green.xpm", &w, &h);
    data->img_ptr[1] = mlx_xpm_file_to_image(data->mlx_ptr, "bg1.xpm", &w, &h);
    data->img_ptr[2] = mlx_xpm_file_to_image(data->mlx_ptr, "monster/1.xpm", &w, &h);
    data->img_ptr[3] = mlx_xpm_file_to_image(data->mlx_ptr, "player/1.xpm", &w, &h);
    data->img_ptr[4] = mlx_xpm_file_to_image(data->mlx_ptr, "player/leftbg.xpm", &w, &h);
    check_ptr_imgs(data, 1);
    data->gate_img[0] = mlx_xpm_file_to_image(data->mlx_ptr, "water/1.xpm", &w, &h);
    data->gate_img[1] = mlx_xpm_file_to_image(data->mlx_ptr, "water/2.xpm", &w, &h);
    data->gate_img[2] = mlx_xpm_file_to_image(data->mlx_ptr, "water/3.xpm", &w, &h);
    data->gate_img[3] = mlx_xpm_file_to_image(data->mlx_ptr, "water/4.xpm", &w, &h);
    data->gate_img[4] = mlx_xpm_file_to_image(data->mlx_ptr, "water/5.xpm", &w, &h);
    data->gate_img[5] = mlx_xpm_file_to_image(data->mlx_ptr, "water/6.xpm", &w, &h);
    data->gate_img[6] = mlx_xpm_file_to_image(data->mlx_ptr, "water/7.xpm", &w, &h);
    data->gate_img[7] = mlx_xpm_file_to_image(data->mlx_ptr, "water/8.xpm", &w, &h);
    data->gate_img[8] = mlx_xpm_file_to_image(data->mlx_ptr, "water/9.xpm", &w, &h);
    check_gate_imgs(data, 1);
}
void f()
{
    system("leaks so_long");
}
int main()
{
    t_data data;
    atexit(f);
    data.mlx_ptr = mlx_init();
    if (!data.mlx_ptr)
        exit(EXIT_FAILURE);
    data.map = get_map("maps.ber");
    if (!data.map)
        exit(EXIT_FAILURE);
    parsing(data.map, "maps.ber");
    data.win_ptr = set_window(data.mlx_ptr, map_demontion("maps.ber"), &data);
    set_img_ptr(&data);
    set_map(&data);
    mlx_hook(data.win_ptr, 2, 0, ft_close, &data);
    mlx_loop_hook(data.mlx_ptr, ft_anime, &data);
    mlx_loop(data.mlx_ptr);
    return (0);
}
