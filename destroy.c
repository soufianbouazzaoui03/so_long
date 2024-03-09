/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 15:30:11 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/05 15:00:04 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_img(t_data *data, int i)
{
	while (i >= 0)
	{
		mlx_destroy_image(data->mlx_ptr, data->img_ptr[i]);
		i--;
	}
}
