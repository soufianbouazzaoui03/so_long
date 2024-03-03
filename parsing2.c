/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 23:53:21 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/03 23:35:29 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	exit_free(char **map)
// {
// 	freemap(map);
// 	exit(EXIT_FAILURE);
// }

// void	check_lines(char **map)
// {
// 	int i;
	
// 	i = 0;
// 	while(map[i])
// 	{
// 		if(!map[i][0])
// 		{
// 			printf("here");
			
// 		}
// 		printf("%s", map[i]);
// 		i++;
// 	}
// }

// void parsing(char **map, char *file)
// {
// 	char **mapcpy;

// 	//check_lines(map);
// 	if (checklen(map))
// 		 return(freemap(map), exit(0));
// 	if (checklastline(file))
// 		return(freemap(map), exit(0));
// 	if (checkelement(map))
// 		 return(freemap(map), exit(0));
// 	if (checkones(map, file))
// 		 return(freemap(map), exit(0));
// 	if (checkone(map))
// 		 return(freemap(map), exit(0));
// 	mapcpy = get_map(file);
// 	if (!mapcpy)
// 		 return(freemap(map), exit(0));
// 	if (checkfor_c(mapcpy))
// 	{
// 		freemap(mapcpy);
// 		return(freemap(map), exit(0));
// 	}
// 	freemap(mapcpy);
// }

// t_map	map_demontion(char *file)
// {
// 	t_map	demontion;
// 	char	*line;
// 	int		fd;
	
// 	fd = open(file, O_RDONLY);
// 	if (fd < 0) 
// 		exit(EXIT_FAILURE);
// 	if (!(line = get_next_line(fd)) || !line[1])
// 	{
// 		if(line)
// 			free(line);
// 		close(fd);
// 		exit(EXIT_FAILURE);
// 	}
// 	demontion.x = ft_strlen(line) - 1;
// 	demontion.y = 0;
// 	free(line);
// 	while ((line = get_next_line(fd)) && line[1])
// 	{
// 		demontion.y++;
// 		free(line);
// 	}
// 	return (close(fd), demontion);
// }





// int main()
// {
// 	int i = 14;
// 	int j = 3;
// 	char **map;

// 	map = get_map("maps.ber");
// 	printf("%d", checkone(map));
// }