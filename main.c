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
	int i;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)//error open file
		return (1);
	i = 0;
	while (i < 5)
	{
		
		next_line = get_next_line(fd);
		count++;
		printf("[%d]:%s", count, next_line);
		next_line = NULL;
		i++;
	}
	close(fd);
	return (0);
}
