/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:24:34 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/21 13:31:39 by abmahfou         ###   ########.fr       */
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
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		lines = ft_strjoin(lines, buff);
		if (found_newline(lines) > 0)
			break ;
	}
	return (lines);
}

char	*extract_line(char *line)
{
	int		i;
	char	*l;

	if (!line)
		return (NULL);
	i = found_newline(line);
	if (i == 0)
	{
		while (line[i])
			i++;
	}
	l = ft_calloc(i + 1, sizeof(char));
	if (l == NULL)
		return (NULL);
	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
		{
			l[i] = line[i];
			break ;
		}
		l[i] = line[i];
		i++;
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
		return (NULL);
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
	
	line = get_next_line(fd);
	printf("%s", line);
} */