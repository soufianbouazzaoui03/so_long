/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-bou <soel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 21:27:45 by soel-bou          #+#    #+#             */
/*   Updated: 2024/03/02 19:06:59 by soel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int checker(const char *file) {
    if (!file)
        return 1;

    if (checklenght(file)) {
		printf("here1");
        return 1;
    }

    if (checkwall(file)) {
		printf("here2");
        return 1;
    }

    if (checkborder(file)) {
		printf("here3");
        return 1;
    }

    if (checkforletters(file)) {
		printf("here4");
        return 1;
    }

    if (checkPE(file, 'C')) {
		printf("here5");
        return 1;
    }

    if (checkPE(file, 'P')) {
		printf("here6");
        return 1;
    }

    if (checkcoin(file)) {
		printf("here7");
        return 1;
    }

    return 0;
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
	if(line[len] == '\n')
	{
		newline = malloc(sizeof(char) * len - 1);
		if(!newline)
			return (free(line), NULL);
		while(i < len)
		{
			newline[i] = line[i];
			i++;
		}
		line[i] = '\0';
		free(line);
		return (newline);
	}
	return (line);
}

int checklenght(const char *file)
{
	int		fd;
	char	*line;
	int		len;
	
	fd = open(file, O_RDONLY);
	if(fd < 0)
		return(1);
	line = get_next_line(fd);
	line = removen(line);
	if (!line)
		return (close(fd), 1);
	len = ft_strlen(line);
	while(1)
	{
		line = get_next_line(fd);
		line = removen(line);
		if(!line)
			break ;
		if (ft_strlen(line) != (size_t)len)
			return (free(line), close(fd), 1);
		free(line);
	}
	return (close(fd), 0);
}

int	checkline(int fd)
{
	char	*line;
	size_t 	i;

	i = 0;
	line = get_next_line(fd);
	line = removen(line);
	if(!line)
		return (1);
	while(line[i] && i < ft_strlen(line))
	{
		if(line[i] != '1')
			return (free(line), close(fd), 1);
		i++;
	}
	return (free(line),close(fd), 0);
}

int checkwall(const char *file)
{
	int		fd;
	int		last;
	char	*line;

	fd = open(file, O_RDONLY);
	if(fd < 0)
		return(1);
	if (checkline(fd))
		return (1);
	fd = open(file, O_RDONLY);
	if(fd < 0)
		return(1);
	last = map_demontion(fd)->y - 1;
	close(fd);
	fd = open(file, O_RDONLY);
	if(fd < 0)
		return(1);
	while(last--)
	{
		line = get_next_line(fd);
		free(line);
	}
	if (checkline(fd))
		return (1);
	return (0);
}

int checkborder(const char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if(fd < 0)
		return(1);
	while(1)
	{
		line = get_next_line(fd);
		line = removen(line);
		if (!line)
			break ;
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (free(line), close(fd), 1);
		free(line);
	}
	return (close(fd), 0);
}

int	checkPE(const char *file , char c)
{
	int		fd;
	char	*line;
	int		mark;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return(1);
	mark = 0;
	while (1)
	{
		line = get_next_line(fd);
		line = removen(line);
		if (!line)
			break ;
		while (*line)
		{
			if (*line == c && mark == 0)
				mark++;
			else if (*line == c && mark > 0)
				return (free(line), close(fd), 1);
			line++;
		}
		free(line);
	}
	return (close(fd), 0);
}

int checkforletters(const char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if(fd < 0)
		return(1);
	while (1)
	{
		line = get_next_line(fd);
		line = removen(line);
		if (!line)
			break ;
		while (*line)
		{
			if (*line != '1' || *line != '0' || *line != 'E' || *line != 'P' || *line != 'C')
				return (free(line), close(fd), 1);
			line++;
		}
		free(line);
	}
	return (close(fd), 0);
}
int	checkcoin(const char *file)
{
	int		fd;
	char	*line;
	int		mark;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return(1);
	mark = 0;
	while (1)
	{
		line = get_next_line(fd);
		line = removen(line);
		if (!line)
			break ;
		while (*line)
		{
			if (*line == 'C')
				mark++;
			line++;
		}
		free(line);
	}
	if(mark < 1)
		return (close(fd), 1);
	return (close(fd), 0);
}

int main()
{
	int fd = open("maps.txt", O_RDONLY);
	char *line = get_next_line(fd);
	line = removen(line);
	printf("%s", line);
	line = get_next_line(fd);
	line = removen(line);
	printf("%s", line);
	line = get_next_line(fd);
	line = removen(line);
	printf("%s", line);
	line = get_next_line(fd);
	line = removen(line);
	printf("%s", line);
	line = get_next_line(fd);
	line = removen(line);
	printf("%s", line);
	line = get_next_line(fd);
	line = removen(line);
	printf("%s", line);
}