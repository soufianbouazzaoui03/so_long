/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 16:46:41 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/04 21:35:52 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

void	free_all(t_data *data)
{
	freemap(data->map);
	ft_destroy_img(data, 5);
}

void	exit_free(char **map)
{
	freemap(map);
	ft_putstr_fd("MAP_ERROR\n", 2);
	exit(EXIT_FAILURE);
}

void	exit_free_line(char *line)
{
	free(line);
	ft_putstr_fd("MAP_ERROR\n", 2);
	exit(EXIT_FAILURE);
}
