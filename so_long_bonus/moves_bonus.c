/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:18:23 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/08 17:18:48 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_close(int key, t_data *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		free_all(data);
		exit(0);
	}
	if (key == 2)
		moveshandler(data, 'D');
	if (key == 0)
		moveshandler(data, 'A');
	if (key == 13)
		moveshandler(data, 'W');
	if (key == 1)
		moveshandler(data, 'S');
	exitwindow(data);
	return (0);
}

void	moveshandler(t_data *data, char move)
{
	handlemoves(data, data->map, move);
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

int	stillcoins(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	handlemoves(t_data *data, char **map, char key)
{
	if (!map || !*map)
		exit(EXIT_FAILURE);
	if (key == 'D')
	{
		if (moveplayer_d(map, stillcoins(map)))
			data->moves++;
	}
	else if (key == 'A')
	{
		if (moveplayer_a(map, stillcoins(map)))
			data->moves++;
	}
	else if (key == 'S')
	{
		if (moveplayer_s(map, stillcoins(map)))
			data->moves++;
	}
	else if (key == 'W')
	{
		if (moveplayer_w(map, stillcoins(map)))
			data->moves++;
	}
	else
		return ;
}
