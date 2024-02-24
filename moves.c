/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 20:18:23 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/23 22:28:42 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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