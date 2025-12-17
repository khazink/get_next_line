/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:28:06 by kkaman            #+#    #+#             */
/*   Updated: 2025/12/17 18:13:19 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//extact line by line until newline
//then return extra line until \0
char	*extra_line(char *store)
{
	char	*extra;
	int		i;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++
	if (store[i] == '\0')
	{
		free(store);
		return (NULL);
	}
	i++;
	if (*store == '\n')
	{
		while (store[i])
			i++;
	}
	extra = malloc((i+1) * sizeof(char));
	i = 1;
	while (store[i])
	{
		extra[i] = store[i];
		i++;
	}
	extra[i] = '\0';
	return (extra);
}
//extract one by one in store and stop until new line

char	*extract_line(char *store)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = store[j];
		j++;
	}
	if (store[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}
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
	return (store);
}

//read file - 1 function
//append dalam static if belom jumpa new line - 1 function sama degan read
//extract static variable sampai new line. 1 function
//1 function untuk 
char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	store = read_append(fd, store);
	line = extract_line(store);
	store = extra_line(store);
	return (line);
}
