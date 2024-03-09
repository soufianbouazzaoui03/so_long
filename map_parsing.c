/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:45:23 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/07 22:20:07 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_free_erro(char **map)
{
	ft_putstr_fd("Error\n", 2);
	exit_free(map);
}

t_map	get_player_pos(char **map)
{
	int		i;
	int		j;
	t_map	pos;

	pos.x = 0;
	pos.y = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

int	checkfor_c(char **map)
{
	int	i;
	int	j;

	i = get_player_pos(map).y;
	j = get_player_pos(map).x;
	floodfill(map, i, j);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
