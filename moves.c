/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:18:23 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/03 16:13:45 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveshandler(t_data *data, char move)
{
    data->moves++;
    handlemoves(data->map, move);
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
	int i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	handlemoves(char **map, char key)
{
	if(!map || !*map)
		exit(EXIT_FAILURE);
	if(key == 'D')
		moveplayerD(map, stillcoins(map));
	else if(key == 'A')
		moveplayerA(map, stillcoins(map));
	else if(key == 'S')
		moveplayerS(map, stillcoins(map));
	else if(key == 'W')
		moveplayerW(map, stillcoins(map));
	else
		return ;
}