/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:53:21 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/03 15:29:40 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



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