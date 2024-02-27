/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 00:06:40 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/27 02:29:18 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int ft_anime_gate(t_data *data)
{
    static int j;

    if (j == 800)
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        set_map(data);
        data->gate++;
        if (data->gate == 8)
            data->gate = 0;
        j = 0;
    }
    j++;
    
    return (0);
}


void    set_gold_imgs(t_data *data)
{
    int w;
    int h;

    data->gold_img[0] = mlx_xpm_file_to_image(data->mlx_ptr, "gold/1.xpm", &w, &h);
    data->gold_img[1] = mlx_xpm_file_to_image(data->mlx_ptr, "gold/2.xpm", &w, &h);
    data->gold_img[2] = mlx_xpm_file_to_image(data->mlx_ptr, "gold/3.xpm", &w, &h);
    data->gold_img[3] = mlx_xpm_file_to_image(data->mlx_ptr, "gold/4.xpm", &w, &h);
    data->gold_img[4] = mlx_xpm_file_to_image(data->mlx_ptr, "gold/5.xpm", &w, &h);
    data->gold_img[5] = mlx_xpm_file_to_image(data->mlx_ptr, "gold/6.xpm", &w, &h);
    data->gold_img[6] = mlx_xpm_file_to_image(data->mlx_ptr, "gold/7.xpm", &w, &h);
    data->gold_img[7] = mlx_xpm_file_to_image(data->mlx_ptr, "gold/8.xpm", &w, &h);
    data->gold_img[8] = mlx_xpm_file_to_image(data->mlx_ptr, "gold/9.xpm", &w, &h);
    data->gold_img[9] = mlx_xpm_file_to_image(data->mlx_ptr, "gold/10.xpm", &w, &h);
}
int ft_anime_gold(t_data *data)
{
    static int j;

    if (j == 800)
    {
        mlx_clear_window(data->mlx_ptr, data->win_ptr);
        set_map(data);
        data->gold++;
        if (data->gold == 9)
            data->gold = 0;
        j = 0;
    }
    j++;
    return (0);
}