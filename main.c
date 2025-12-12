/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkaman <kkaman@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:32:31 by kkaman            #+#    #+#             */
/*   Updated: 2025/12/12 18:08:42 by kkaman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int	main(void)
{
	int	fd;
	char	*next_line;
	int	count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)//error open file
	return (1);
	next_line = get_next_line(fd);
	if (next_line == NULL)
		printf("NULL on GNL");
	count++;
	printf("[%d]:%s\n", count, next_line);
	next_line = NULL;
	close(fd);
	return (0);
}
