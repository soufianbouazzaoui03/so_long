/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:46:41 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/03 16:17:04 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void freemap(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void    free_all(t_data *data)
{
    freemap(data->map);
    free(data->moves_string);
    ft_destroy_gate(data, 8);
    ft_destroy_gold(data, 9);
    ft_destroy_img(data, 4);
}