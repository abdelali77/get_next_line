/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:24:34 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/24 14:14:51 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(char *lines, int fd)
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
			free(lines);
			return (free(buff), NULL);
		}
		buff[bytes] = '\0';
		lines = ft_strjoin(lines, buff);
		if (found_newline(lines) > 0)
			break ;
	}
	free(buff);
	return (lines);
}

char	*extract_line(char *line)
{
	int		len;
	char	*l;

	if (!line)
		return (NULL);
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
	static char	*lines;
	char		*nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (found_newline(lines) == 0)
		lines = create_line(lines, fd);
	if (!lines || lines[0] == '\0')
	{
		free(lines);
		lines = NULL;
		return (NULL);
	}
	nl = extract_line(lines);
	lines = line_remaining(lines);
	return (nl);
}

/* #include <stdio.h>
#include <fcntl.h>
int main()
{
	int fd = open("file.txt", O_RDONLY);
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
} */