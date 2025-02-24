/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keanders <keanders@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:26:43 by keanders          #+#    #+#             */
/*   Updated: 2025/02/23 19:53:43 by keanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer, char **remainder)
{
	ssize_t	bytes_read;
	char	*temp;

	while (!ft_strchr(*remainder, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (bytes_read == 0 && **remainder == '\0') // EOF and no data left
			{
				free(*remainder);
				*remainder = NULL;
				return (NULL);
			}
			break ;
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*remainder, buffer);
		free(*remainder);
		*remainder = temp;
		if (!*remainder)
			return (NULL);
	}
	return (*remainder);
}

static char	*copy_line(char *remainder, char *newline_pos)
{
	char	*line;
	size_t	i;

	line = malloc(newline_pos - remainder + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (i < (size_t)(newline_pos - remainder + 1))
	{
		line[i] = remainder[i];
		i++;
	}
	line[newline_pos - remainder + 1] = '\0';
	return (line);
}

static char	*extract_line(char **remainder)
{
	char	*line;
	char	*newline_pos;
	char	*temp;

	newline_pos = ft_strchr(*remainder, '\n');
	if (newline_pos)
	{
		line = copy_line(*remainder, newline_pos);
		if (!line)
			return (NULL);
		temp = ft_strdup(newline_pos + 1);
		free(*remainder);
		*remainder = temp;
	}
	else
	{
		line = ft_strdup(*remainder);
		free(*remainder);
		*remainder = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	line = read_line(fd, buffer, &remainder);
	free(buffer);
	if (!line)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	return (extract_line(&remainder));
}
