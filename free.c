/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:46:41 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/02 20:36:32 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_destroy_gold(t_data *data, int i)
{
    while(i >= 0)
    {
        mlx_destroy_image(data->mlx_ptr, data->gold_img[i]);
        i--;
    }
}
void    ft_destroy_gate(t_data *data, int i)
{
    while(i >= 0)
    {
        mlx_destroy_image(data->mlx_ptr, data->gate_img[i]);
        i--;
    }
}
void    ft_destroy_img(t_data *data, int i)
{
    while(i >= 0)
    {
        mlx_destroy_image(data->mlx_ptr, data->img_ptr[i]);
        i--;
    }
}

void    free_data(t_data *data)
{
    freemap(data->map);
    free(data->moves_string);
}

void    free_all(t_data *data)
{
    //free_imgs(data);
    free_data(data);
}