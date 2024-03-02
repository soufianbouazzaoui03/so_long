/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:45:23 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/02 22:16:22 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*removen(char *line)
{
	char	*newline;
	int 	len;
	int		i;

	i = 0;
	if(!line)
		return (NULL);
	len = ft_strlen(line);
	if(line[len - 1] == '\n')
	{
		newline = (char *)malloc(sizeof(char) * (len - 1));
		if(!newline)
			return (NULL);
		while(line[i] != '\n' && line[i])
		{
			newline[i] = line[i];
			i++;
		}
		newline[i] = '\0';
		free(line);
		return (newline);
	}
	return (line);
}

char	**get_map(char *file)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;
	int 	y;

	fd = open(file, O_RDONLY);
	i = 0;
	if(fd < 0)
		exit(EXIT_FAILURE);
	y = map_demontion(file).y;
	map = (char **)malloc(sizeof(char *) * (y + 1));
	if(!map)
		return (close(fd), exit(EXIT_FAILURE), NULL);
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		map[i++] = removen(line);
		y--;
	}
	map[i] = NULL;
	return (close(fd), map);
}

void floodfill(char **map, int i, int j)
{
	if (map[i - 1][j] == 'C' || map[i - 1][j] == '0' || map[i - 1][j] == 'E')
	{
	map[i - 1][j] = 'V';
		floodfill(map, i - 1, j);
	}
	if (map[i + 1][j] == 'C' || map[i + 1][j] == '0' || map[i + 1][j] == 'E')
	{
		map[i + 1][j] = 'V';
		floodfill(map, i + 1, j);
	}
	if (map[i][j - 1] == 'C' || map[i][j - 1] == '0' || map[i][j - 1] == 'E')
	{
		map[i][j - 1] = 'V';
		floodfill(map, i, j - 1);
	}
	if (map[i][j + 1] == 'C' || map[i][j + 1] == '0' || map[i][j + 1] == 'E')
	{
		map[i][j + 1] = 'V';
		floodfill(map, i, j + 1);
	}
}

t_map get_player_pos(char **map)
{
	int i;
	int j;
	t_map	pos;
    pos.x = 0;
    pos.y = 0;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return pos;
}

int	checkfor_c(char **map)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}