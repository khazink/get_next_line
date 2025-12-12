/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:28:06 by kkaman            #+#    #+#             */
/*   Updated: 2025/12/12 18:23:37 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read return byte read which is number of byte that have been read. if less than byte requested might be interuption or eof. if 0 mean eof <0 means error
//buffer only store value from read. need to tranfer/append to store if not value gone
char	*read_append(int fd, char *store)
{
	ssize_t	byte_read;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(store, '\n') && byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		store = ft_strjoin(store, buffer);
		if (!store)
		{
			free(buffer);
			return (NULL);
		}
	}
	return (buffer);
}

//read file - 1 function
//append dalam static if belom jumpa new line - 1 function sama degan read
//extract static variable sampai new line. 1 function
//1 function untuk 
char	*get_next_line(int fd)
{
	static char	*store;
//	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_append(fd, store);
	return (store);
}
