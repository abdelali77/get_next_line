/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:17:43 by abmahfou          #+#    #+#             */
/*   Updated: 2024/02/22 11:33:45 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*create_line(char *line, int fd)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
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
	l = malloc((len + 1) * sizeof(char));
	if (l == NULL)
		return (NULL);
	len = 0;
	while (line[len])
	{
		l[len] = line[len];
		if (line[len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	l[len] = '\0';
	return (l);
}

char	*get_next_line(int fd)
{
	static char	*lines[257];
	char		*nl;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
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
