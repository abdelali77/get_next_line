/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:24:34 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/29 12:58:07 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char	*e_l;

	len = found_newline(line);
	if (len == 0)
	{
		while (line[len])
			len++;
	}
	e_l = malloc((len + 1) * sizeof(char));
	if (e_l == NULL)
		return (NULL);
	len = 0;
	while (line[len])
	{
		e_l[len] = line[len];
		if (line[len] == '\n')
		{
			len++;
			break ;
		}
		len++;
	}
	e_l[len] = '\0';
	return (e_l);
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
