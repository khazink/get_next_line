/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:28:06 by kkaman            #+#    #+#             */
/*   Updated: 2025/12/18 21:31:59 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*extra_line(char *store)
{
	char	*extra;
	int		i;
	int		j;

	if (!store)
		return (NULL);
	i = 0;
	while (store[i] && store[i] != '\n')
		i++;
	if (store[i] == '\0')
		return (free(store), NULL);
	j = i++;
	while (store[j])
		j++;
	if (j - i == 0)
		return (free(store), NULL);
	extra = malloc(((j - i) + 1) * sizeof(char));
	j = 0;
	while (store[i])
		extra[j++] = store[i++];
	free(store);
	extra[j] = '\0';
	return (extra);
}

char	*extract_line(char *store)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	if (!store || !store[0])
		return (NULL);
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

char	*read_append(int fd, char *store)
{
	ssize_t	byte_read;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	byte_read = 1;
	while (!ft_strchr(store, '\n') && byte_read != 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read < 0)
		{
			free(buffer);
			free(store);
			return (NULL);
		}
		buffer[byte_read] = '\0';
		store = ft_strjoin(store, buffer);
		if (!store)
			return (free(buffer), NULL);
	}
	return (free(buffer), store);
}

char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = read_append(fd, store[fd]);
	if (!store[fd])
		return (NULL);
	line = extract_line(store[fd]);
	store[fd] = extra_line(store[fd]);
	return (line);
}
