/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:17:43 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/24 18:03:09 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(char *line, int fd)
{
	char	*buff;
	int		bytes;

	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buff == NULL)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(line);
			return (free(buff), NULL);
		}
		buff[bytes] = '\0';
		line = ft_strjoin(line, buff);
		if (found_newline(line) > 0)
			break ;
	}
	free(buff);
	return (line);
}

char	*extract_line(char *line)
{
	int		len;
	char	*l;

	len = found_newline(line);
	if (len == 0)
	{
		while (line[len])
			len++;
	}
	l = ft_calloc(len + 1, sizeof(char));
	if (l == NULL)
		return (NULL);
	len = 0;
	while (line[len])
	{
		if (line[len] == '\n')
		{
			l[len] = line[len];
			break ;
		}
		l[len] = line[len];
		len++;
	}
	return (l);
}

char	*get_next_line(int fd)
{
	static char	*lines[10240];
	char		*nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (found_newline(lines[fd]) == 0)
		lines[fd] = create_line(lines[fd], fd);
	if (!lines[fd] || lines[fd][0] == '\0')
	{
		free(lines[fd]);
		lines[fd] = NULL;
		return (NULL);
	}
	nl = extract_line(lines[fd]);
	lines[fd] = line_remaining(lines[fd]);
	return (nl);
}

/* #include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("file.txt", O_RDONLY);
	int fd2 = open("file2.txt", O_RDONLY);
	char *line;
	char *l;

	line = get_next_line(fd);
	printf("%s", line);
	line = get_next_line(fd);
	printf("%s", line);
	l = get_next_line(fd2);
	printf("%s", l);
	l = get_next_line(fd2);
	printf("%s", l);
} */