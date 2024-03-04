/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksegs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 02:31:41 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/04 20:37:56 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_gold_imgs(t_data *data, int ex)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (!data->gold_img[i])
		{
			ft_destroy_gold(data, i - 1);
			freemap(data->map);
			if (ex == 1)
				ft_putstr_fd("MLX_IMG_ERROR\n", 2);
			exit(ex);
		}
		i++;
	}
}

void	check_gate_imgs(t_data *data, int ex)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		if (!data->gate_img[i])
		{
			ft_destroy_gold(data, 9);
			ft_destroy_img(data, 4);
			ft_destroy_gate(data, i - 1);
			if (ex == 1)
				ft_putstr_fd("MLX_IMG_ERROR\n", 2);
			exit(ex);
		}
		i++;
	}
}

void	check_ptr_imgs(t_data *data, int ex)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (!data->img_ptr[i])
		{
			ft_destroy_gold(data, 9);
			ft_destroy_img(data, i - 1);
			if (ex == 1)
				ft_putstr_fd("MLX_IMG_ERROR\n", 2);
			exit(ex);
		}
		i++;
	}
}
