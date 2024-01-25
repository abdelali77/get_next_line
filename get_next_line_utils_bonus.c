/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:19:10 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/25 17:25:00 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	unsigned char	*calloc_ptr;
	size_t			i;

	i = 0;
	calloc_ptr = malloc(count * size);
	if (calloc_ptr == NULL)
		return (NULL);
	while (i < count)
	{
		calloc_ptr[i] = '\0';
		i++;
	}
	return (calloc_ptr);
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
			return (NULL);
	}
	str = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
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
		remain = ft_calloc(1, sizeof(char));
		if (remain == NULL)
			return (NULL);
	}
	else
	{
		remain = ft_calloc(ft_strlen(line) - i + 1, sizeof(char));
		if (remain == NULL)
			return (NULL);
		while (line[i])
			remain[j++] = line[i++];
	}
	free(line);
	return (remain);
}
