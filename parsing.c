/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:06:08 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/03 23:32:50 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parsnew_line(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		exit_free_line(line);
	while (line[i] && line[i + 1])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			exit_free_line(line);
		i++;
	}
	if (line[i] == '\n')
		exit_free_line(line);
}

void	pars_element(char *line)
{
	int 		i;
	int	p = 0;
	int	e = 0;
	int	c = 0;

	i = 0;
	while (line[i])
	{
		if((line[i] != '0' && line[i] != '1' && line[i] != 'E' && line[i] != 'C' && line[i] != 'P' && line[i] != 'N'  && line[i] != '\n'))
			exit_free_line(line);
		if (line[i] == 'E')
			e++;
		else if (line[i] == 'C')
			c++;
		else if (line[i] == 'P')
			p++;
		i++;
	}
	if (e != 1 || p != 1 || c < 1)
		exit_free_line(line);
}

void	check_ones(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][i])
	{
		if(map[0][i++] != '1')
			exit_free(map);
	}
	i = 0;
	while (map[i])
		i++;
	while (map[i - 1][j])
	{
		if(map[i - 1][j] != '1')
			exit_free(map);
		j++;
	}
}
void	check_argv(char *map)
{
	int i;
	
	if (!map)
		exit(EXIT_FAILURE);
	i = 0;
	while (map[i])
		i++;
	if (ft_strncmp(&map[i - 4], ".ber", 4))
		exit(EXIT_FAILURE);
}

void	checkfor_c(char **map)
{
	int i;
	int j;

	i = get_player_pos(map).y;
	j = get_player_pos(map).x;
	floodfill(map, i, j);
	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C' || map[i][j] == 'E')
				exit_free(map);
			j++;
		}
		i++;
	}
}
// void	f()
// {
// 	system("leaks a.out");
// }

// int main()
// {
// 	int i = 0;
// 	char *line;

// 	atexit(f);
// 	line = get_map_line("maps.ber");
// 	parsnew_line(line);
// 	pars_element(line);
// 	char **map = get_map2(line);
// 	while(map[i])
// 	printf("%s\n", map[i++]);
// 	freemap(map);
// }