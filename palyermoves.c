/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palyermoves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 21:01:43 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/24 01:20:05 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveplayerD(char **map, int iscoins)
{
	int	i;
	int	j;

	i = 0;

	while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P' && (map[i][j + 1] == '0' || map[i][j + 1] == 'C'|| map[i][j + 1] == 'E'))
            {
                map[i][j] = '0';
                if(iscoins == 0 && map[i][j + 1] == 'E')
                    map[i][j + 1] = 'X';
                else
                    map[i][j + 1] = 'P';
                return ;
            }
            j++;
        }
        i++;
    }
}

void	moveplayerA(char **map, int iscoins)
{
	int	i;
	int	j;

	i = 0;

	while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P' && (map[i][j - 1] == '0' || map[i][j - 1] == 'C'|| map[i][j - 1] == 'E'))
            {
                map[i][j] = '0';
                if(iscoins == 0 && map[i][j - 1] == 'E')
                    map[i][j - 1] = 'X';
                else
                    map[i][j - 1] = 'P';
                return ;
            }
            j++;
        }
        i++;
    }
}

void	moveplayerW(char **map, int iscoins)
{
	int	i;
	int	j;

	i = 0;

	while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P' && (map[i - 1][j] == '0' || map[i - 1][j] == 'C' || map[i - 1][j] == 'E'))
            {
                map[i][j] = '0';
                if(iscoins == 0 && map[i - 1][j] == 'E')
                    map[i - 1][j] = 'X';
                else
                    map[i - 1][j] = 'P';
                return ;
            }
            j++;
        }
        i++;
    }
}

void	moveplayerS(char **map, int iscoins)
{
	int	i;
	int	j;

	i = 0;

	while(map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if(map[i][j] == 'P' && (map[i + 1][j] == '0' || map[i + 1][j] == 'C'|| map[i + 1][j] == 'E'))
            {
                map[i][j] = '0';
                if(iscoins == 0 && map[i + 1][j] == 'E')
                    map[i + 1][j] = 'X';
                else
                    map[i + 1][j] = 'P';
                return;
            }
            j++;
        }
        i++;
    }
}
