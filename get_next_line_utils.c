/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:30:00 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/22 19:22:17 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void			*calloc_ptr;
	unsigned char	*p;
	size_t			i;

	i = 0;
	calloc_ptr = malloc(count * size);
	if (calloc_ptr == NULL)
		return (free(calloc_ptr), NULL);
	p = (unsigned char *)calloc_ptr;
	while (i < count)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = ft_calloc(1, sizeof(char));
		if (s1 == NULL)
			return (free(s1), NULL);
	}
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (str == NULL)
		return (free(str), NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	free(s1);
	return (str);
}

int	found_newline(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (0);
}

char	*line_remaining(char *line)
{
	int		i;
	int		j;
	char	*remain;

	i = found_newline(line);
	j = 0;
	if (!line)
		return (NULL);
	if (i == 0)
	{
		remain = ft_calloc(1, 1);
		if (remain == NULL)
			return (free(remain), NULL);
		return (remain);
	}
	else
	{
		remain = ft_calloc(ft_strlen(line) - i + 1, sizeof(char));
		if (remain == NULL)
			return (free(remain), NULL);
		while (line[i])
			remain[j++] = line[i++];
	}
	free(line);
	return (remain);
}
