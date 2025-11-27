/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:28:06 by kkaman            #+#    #+#             */
/*   Updated: 2025/11/27 17:04:06 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	ssize_t	bytes_read;
	char	buffer[1024];

	if (fd < 0 || buffer <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, 6);
	return (buffer);
}
