/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sifex <Sifex@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 01:34:46 by Sifex             #+#    #+#             */
/*   Updated: 2023/11/20 01:34:46 by Sifex            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		write(fd, &s[i++], 1);
}

int	main(void)
{
	char	*line;
	char	*line2;
	char	*line3;
	int		fd;
	int		fd2;
	int		fd3;

	fd = open("test.txt", O_RDONLY);
	fd2 = open("test en bien.txt", O_RDONLY);
	fd3 = open("oklmzer.txt", O_RDONLY);

	printf("BUFFER_SIZE -> %d\n", BUFFER_SIZE);
	//printf("-->%s", get_next_line(fd));

	line = get_next_line(fd);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);
	while (line)
	{
		printf("line 1 -->%s", line);
		if (line2)
			printf("line 2 -->%s", line2);
		if (line3)
			printf("line 3 -->%s", line3);
		free(line);
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
	}

	/*line = get_next_line(fd);
	while (line)
	{
		printf("line 1 -->%s", line);
		free(line);
		line = get_next_line(fd);
	}*/
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}

// cc *.c
// cc *_bonus.c main.c
