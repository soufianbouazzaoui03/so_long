/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:53:21 by soel-bou          #+#    #+#             */
/*   Updated: 2024/02/24 01:54:26 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	map_demontion(char *file)
{
	t_map	demontion;
	char	*line;
	int		fd;
	
	fd = open(file, O_RDONLY);
	if(fd < 0)
		exit(EXIT_FAILURE);
	// demontion = malloc(sizeof(t_map));
	// if(!demontion)
	// 	exit(EXIT_FAILURE);
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	demontion.x = ft_strlen(line) - 1;
	demontion.y = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		demontion.y++;
		free(line);
	}
	return (close(fd), demontion);
}

char	*removen(char *line)
{
	char	*newline;
	int 	len;
	int		i;

	i = 0;
	if(!line)
		return (NULL);
	len = ft_strlen(line);
	if(len < 2)
		return (line);
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


// void	freelist(char **list, int size)
// {
// 	int	i;

// 	i = 0;
// 	while(i < size)
// 		free(list[i++]);
// 	free(list);
// }

char	**get_map(char *file)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	if(fd < 0)
		exit(EXIT_FAILURE);
	map = (char **)malloc(sizeof(char *) * (map_demontion(file).y + 1));
	if(!map)
		return (close(fd), exit(EXIT_FAILURE), NULL);
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		map[i++] = removen(line);
	}
	map[i] = NULL;
	return (close(fd), map);
}

int		checklen(char **map)
{
	int i;

	i = 0;
	while(map[i] && map[i + 1])
	{
		if(ft_strlen(map[i]) != ft_strlen(map[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

int	checkone(char **map)
{
	//call after checking all line in map are equales.
	int i;

	i = 0;
	while(map[i])
	{
		if(map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int checkelement(char **map)
{
	int i;
	int j;
	int p;
	int e;
	int c;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if(map[i][j] == 'C')
				c++;
			else if(map[i][j] == 'P')
				p++;
			else if(map[i][j] == 'E')
				e++;
			else if(map[i][j] != '1' && map[i][j] != '0')
				return (1);
			j++;
		}
		i++;
	}
	if(c < 1 || p != 1 || e != 1)
			return (1);
	return (0);
}

void printmap(char **map)
{
	int i;

	i = 0;
	printf("---------------------\n");
	while(map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

// int main()
// {
// 	char **map;

// 	map = get_map("maps.txt");
// 	printmap(map);
// 	moveplayerS(map, 0);
// 	printmap(map);
// }