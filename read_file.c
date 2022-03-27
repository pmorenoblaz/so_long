/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:01:35 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/03/27 12:03:31 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_read_map(char *file)
{
	int		fd;
	char	*line;
	size_t	pos[2];

	pos[1] = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	pos[0] = ft_strlen(line);
	while (line)
	{
		pos[1]++;
		if (ft_strlen(line) != pos[0])
		{
			free(line);
			return (0);
		}
		printf("%s", line);
		if (line && ft_strlen(line) > 0)
			free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (1);
}
