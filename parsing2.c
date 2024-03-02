/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:53:21 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/02 22:49:34 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void freemap(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void parsing(char **map, char *file)
{
	char **mapcpy;

	if (checklen(map))
		return (freemap(map), exit(EXIT_FAILURE));
	if (checklastline(file))
		exit(EXIT_FAILURE);
	if (checkelement(map))
		return (freemap(map), exit(EXIT_FAILURE));
	if (checkones(map, file))
		return (freemap(map), exit(EXIT_FAILURE));
	if (checkone(map))
		return (freemap(map), exit(EXIT_FAILURE));
	mapcpy = get_map(file);
	if (checkfor_c(mapcpy))
	{
		freemap(mapcpy);
		return (freemap(map), exit(EXIT_FAILURE));
	}
	freemap(mapcpy);
}

t_map	map_demontion(char *file)
{
	t_map	demontion;
	char	*line;
	int		fd;
	
	fd = open(file, O_RDONLY);
	if(fd < 0) 
		exit(EXIT_FAILURE);
	if (!(line = get_next_line(fd)) || !line[1])
	{
		if(!line[1])
			free(line);
		close(fd);
		exit(EXIT_FAILURE);
	}
	demontion.x = ft_strlen(line) - 1;
	demontion.y = 0;
	free(line);
	while ((line = get_next_line(fd)))
	{
		demontion.y++;
		free(line);
	}
	return (free(line), close(fd), demontion);
}

int checklastline(char *file)
{
	int 	y;
	char	*line;
	int 	fd;
	int i;

	i = 0;
	fd = open(file, O_RDONLY);
	if(fd < 0)
		return (1);	
	y = map_demontion(file).y;
	while(1)
	{
		line = get_next_line(fd);
		if(y == 0)
			break;
		else
			free(line);
		y--;
	}
	while(line[i])
	{
		if(line[i++] == '\n')
			return(free(line), close(fd), 1);
	}
	return (free(line), close(fd), 0);
}

int		checklen(char **map)
{
	int 	i;
	size_t 	le;

	if (!map || !*map)
		return (1);
	le = ft_strlen(map[1]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != le)
			return (1);
		i++;
	}
	return (0);
}

int	checkone(char **map)
{
	int i;

	i = 0;
	if (!map || !*map)
		return (1);
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int checkelement(char **map)
{
	t_element elem;

	elem.e = 0;
	elem.c = 0;
	elem.i = -1;
	elem.p = 0;
	while(map[++elem.i])
	{
		elem.j = -1;
		while(map[elem.i][++elem.j])
		{
			if(map[elem.i][elem.j] == 'C')
				elem.c++;
			else if(map[elem.i][elem.j] == 'P')
				elem.p++;
			else if(map[elem.i][elem.j] == 'E')
				elem.e++;
			else if(map[elem.i][elem.j] != '1' && map[elem.i][elem.j] != '0' 
					&& map[elem.i][elem.j] != '\n' && map[elem.i][elem.j] != 'N')
				return (1);
		}
	}
	if(elem.c < 1 || elem.p != 1 || elem.e != 1)
			return (1);
	return (0);
}

int checkones(char **map, char *file)
{
	int y;
	int	i;

	i = 0;
	y = map_demontion(file).y;
	while (map[0][i] && map[y][i])
	{
		if (map[0][i] != '1' || map[y][i++] != '1')
			return (1);
	}
	return (0);
}

// void printmap(char **map)
// {
// 	int i;

// 	i = 0;
// 	printf("---------------------\n");
// 	while(map[i])
// 	{
// 		printf("%s\n", map[i]);
// 		i++;
// 	}
// }

// int main()
// {
// 	int i = 14;
// 	int j = 3;
// 	char **map;

// 	map = get_map("maps.ber");
// 	printf("%d", checkone(map));
// }