/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 17:36:45 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/02 17:37:14 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_D(t_data *data, int i, int j)
{
	if(data->map[i][j + 1] == 'P')
	{
		data->map[i][j] = '0';
		data->map[i][j + 1] = 'X';
		exitwindow(data);
	}
	else if(data->map[i][j + 1] == '0')
	{
		data->map[i][j] = '0';
		data->map[i][j + 1] = 'N';
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		set_map(data);
		return (1);
	}
	return (0);
}

int	move_A(t_data *data, int i, int j)
{
	if(data->map[i][j - 1] == 'P')
	{
		data->map[i][j] = '0';
		data->map[i][j - 1] = 'X';
		exitwindow(data);
	}
	else if(data->map[i][j - 1] == '0')
	{
		data->map[i][j] = '0';
		data->map[i][j - 1] = 'N';
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		set_map(data);
		return (1);
	}
	return (0);
}

int	move_W(t_data *data, int i, int j)
{
	if(data->map[i - 1][j] == 'P')
	{
		data->map[i][j] = '0';
		data->map[i - 1][j] = 'X';
		exitwindow(data);
	}
	else if(data->map[i - 1][j] == '0')
	{
		data->map[i][j] = '0';
		data->map[i - 1][j] = 'N';
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		set_map(data);
		return (1);
	}
	return (0);
}

int	move_S(t_data *data, int i, int j)
{
	if(data->map[i + 1][j] == 'P')
	{
		data->map[i][j] = '0';
		data->map[i + 1][j] = 'X';
		exitwindow(data);
	}
	else if(data->map[i + 1][j] == '0')
	{
		data->map[i][j] = '0';
		data->map[i + 1][j] = 'N';
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		set_map(data);
		return (1);
	}
	return (0);
}