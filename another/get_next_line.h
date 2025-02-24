/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keanders <keanders@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:48:57 by keanders          #+#    #+#             */
/*   Updated: 2025/02/23 14:59:16 by keanders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>   // For file operations
# include <stdio.h>   // For perror
# include <stdlib.h>  // For malloc, free
# include <string.h>  // For string operations (if needed)
# include <unistd.h>  // For read, write

// Function Prototypes
char	get_next_byte(int fd);
char	*ft_strcpy(char *dest, const char *src);
char	*get_next_line(int fd);

#endif
