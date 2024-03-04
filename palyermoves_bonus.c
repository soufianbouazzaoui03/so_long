/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palyermoves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:01:43 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/04 20:33:53 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_it(char **map, int i, int j, char c)
{
	if (c == 'd')
	{
		map[i][j] = '0';
		map[i][j + 1] = 'P';
	}
	else if (c == 'a')
	{
		map[i][j] = '0';
		map[i][j - 1] = 'P';
	}
	else if (c == 's')
	{
		map[i][j] = '0';
		map[i + 1][j] = 'P';
	}
	else if (c == 'w')
	{
		map[i][j] = '0';
		map[i - 1][j] = 'P';
	}
}

int	moveplayer_d(char **map, int iscoins)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && (map[i][j + 1] == '0'
				|| map[i][j + 1] == 'C'))
			{
				move_it(map, i, j, 'd');
				return (1);
			}
			else if (map[i][j] == 'P' && (map[i][j + 1] == 'N'
				|| (iscoins == 0 && map[i][j + 1] == 'E')))
			{
				map[i][j] = '0';
				map[i][j + 1] = 'X';
				return (1);
			}
		}
	}
	return (0);
}

int	moveplayer_a(char **map, int iscoins)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && (map[i][j - 1] == '0'
				|| map[i][j - 1] == 'C'))
			{
				move_it(map, i, j, 'a');
				return (1);
			}
			else if (map[i][j] == 'P' && (map[i][j - 1] == 'N'
				|| (iscoins == 0 && map[i][j - 1] == 'E')))
			{
				map[i][j] = '0';
				map[i][j - 1] = 'X';
				return (1);
			}
		}
	}
	return (0);
}

int	moveplayer_w(char **map, int iscoins)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && (map[i - 1][j] == '0'
				|| map[i - 1][j] == 'C'))
			{
				move_it(map, i, j, 'w');
				return (1);
			}
			else if (map[i][j] == 'P' && (map[i - 1][j] == 'N'
				|| (iscoins == 0 && map[i - 1][j] == 'E')))
			{
				map[i][j] = '0';
				map[i - 1][j] = 'X';
				return (1);
			}
		}
	}
	return (0);
}

int	moveplayer_s(char **map, int iscoins)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'P' && (map[i + 1][j] == '0'
				|| map[i + 1][j] == 'C'))
			{
				move_it(map, i, j, 's');
				return (1);
			}
			else if (map[i][j] == 'P' && (map[i + 1][j] == 'N'
				|| (iscoins == 0 && map[i + 1][j] == 'E')))
			{
				map[i][j] = '0';
				map[i + 1][j] = 'X';
				return (1);
			}
		}
	}
	return (0);
}
