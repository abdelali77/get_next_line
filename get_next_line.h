/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abmahfou <abmahfou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:25:28 by abmahfou          #+#    #+#             */
/*   Updated: 2024/01/22 10:38:17 by abmahfou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "stdlib.h"
# include "unistd.h"

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		found_newline(char *line);
char	*line_remaining(char *line);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t count, size_t size);

#endif