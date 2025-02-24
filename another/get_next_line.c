/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keanders <keanders@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:26:43 by keanders          #+#    #+#             */
/*   Updated: 2025/02/23 15:21:58 by keanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	get_next_byte(int fd)
{
	char	byte;
	ssize_t	bytes_read;

	bytes_read = read(fd, &byte, 1);
	if (bytes_read <= 0)
	{
		return ('\0');
	}
	return (byte);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}

static char	*init_str(void)
{
	char	*str;

	str = malloc(1);
	if (!str)
	{
		perror("Failed to allocate memory");
		return (NULL);
	}
	str[0] = '\0';
	return (str);
}

static char	*append_byte(char *str, int *size, size_t *index, char byte)
{
	char	*new_str;

	new_str = malloc(*size + 1);
	if (!new_str)
	{
		perror("Failed to allocate memory");
		free(str);
		return (NULL);
	}
	ft_strcpy(new_str, str);
	free(str);
	new_str[*index] = byte;
	new_str[*index + 1] = '\0';
	(*size)++;
	(*index)++;
	return (new_str);
}

char	*get_next_line(int fd)
{
	int		str_size;
	size_t	index;
	char	*str;
	char	byte;

	str_size = 1;
	index = 0;
	str = init_str();
	if (!str)
		return (NULL);
	while (1)
	{
		byte = get_next_byte(fd);
		if (byte == '\0')
			break ;
		str = append_byte(str, &str_size, &index, byte);
		if (!str)
			return (NULL);
		if (byte == '\n')
			return (str);
	}
	if (index > 0)
		return (str);
	free(str);
	return (NULL);
}
