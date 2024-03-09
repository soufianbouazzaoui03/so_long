/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checksegs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 02:31:41 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/07 22:19:47 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ptr_imgs(t_data *data, int ex)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (!data->img_ptr[i])
		{
			if (ex == 1)
				ft_putstr_fd("Error\nMLX_IMG_ERROR\n", 2);
			exit(ex);
		}
		i++;
	}
}
