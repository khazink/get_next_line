/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:28:06 by kkaman            #+#    #+#             */
/*   Updated: 2025/12/01 18:51:25 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//read return byte read which is number of byte that have been read. if less than byte requested might be interuption or eof. if 0 mean eof <0 means error

char	*read_file(int fd, store)
{
	ssize_t	byte_read;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (byte_read <= 0)
	{
		free(buffer);
		return (NULL);
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
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_append(fd, store);
	return (buffer);
}
