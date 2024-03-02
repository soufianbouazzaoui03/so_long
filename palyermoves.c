/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palyermoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:01:43 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/28 02:33:31 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveplayerD(char **map, int iscoins)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'P' && (map[i][j + 1] == '0' || map[i][j + 1] == 'C'))
            {
                    map[i][j] = '0';
                    map[i][j + 1] = 'P';
                    return ;
            }
            else if (map[i][j] == 'P' && (map[i][j + 1] == 'N' || (iscoins == 0 && map[i][j + 1] == 'E')))
            {
                map[i][j] = '0';
                map[i][j + 1] = 'X';
                return ;
            }
        }
    }
}

void	moveplayerA(char **map, int iscoins)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'P' && (map[i][j - 1] == '0' || map[i][j - 1] == 'C'))
            {
                    map[i][j] = '0';
                    map[i][j - 1] = 'P';
                    return ;
            }
            else if (map[i][j] == 'P' && (map[i][j - 1] == 'N' || (iscoins == 0 && map[i][j - 1] == 'E')))
            {
                map[i][j] = '0';
                map[i][j - 1] = 'X';
                return ;
            }
        }
    }
}

void	moveplayerW(char **map, int iscoins)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'P' && (map[i - 1][j] == '0' || map[i - 1][j] == 'C'))
            {
                    map[i][j] = '0';
                    map[i - 1][j] = 'P';
                    return ;
            }
            else if (map[i][j] == 'P' && (map[i - 1][j] == 'N' || (iscoins == 0 && map[i - 1][j] == 'E')))
            {
                map[i][j] = '0';
                map[i - 1][j] = 'X';
                return ;
            }
        }
    }
}

void	moveplayerS(char **map, int iscoins)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == 'P' && (map[i + 1][j] == '0' || map[i + 1][j] == 'C'))
            {
                    map[i][j] = '0';
                    map[i + 1][j] = 'P';
                    return ;
            }
            else if (map[i][j] == 'P' && (map[i + 1][j] == 'N' || (iscoins == 0 && map[i + 1][j] == 'E')))
            {
                map[i][j] = '0';
                map[i + 1][j] = 'X';
                return ;
            }
        }
    }
}

