/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:30:11 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/05 15:45:10 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_gold(t_data *data, int i)
{
	while (i >= 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->gold_img[i]);
		i--;
	}
}

void	ft_destroy_gate(t_data *data, int i)
{
	while (i >= 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->gate_img[i]);
		i--;
	}
}

void	ft_destroy_img(t_data *data, int i)
{
	while (i >= 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr[i]);
		i--;
	}
}

int	close_win(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free_all(data);
	exit(0);
}
