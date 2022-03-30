/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:01:35 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/03/30 20:18:35 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(char *file, int *x, int *y)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	*y = ft_strlen(line);
	while (line)
	{
		*x++;
		if (ft_strlen(line) != *y)
		{
			free(line);
			close(fd);
			exit (0);
		}
		printf("%s", line);
		if (line && ft_strlen(line) > 0)
			free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
}

void	ft_add_line_to_board(t_board **board, char *line, int x)
{
	int i;

	i = 0;
	while (line[i])
	{
		board->x = x;
		board->y = i;
		board
		i++;
	}
}

void	ft_final_matrix(char *file, t_board **board, int *x, int *y)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		board = malloc(sizeof(t_board) * y);
		ft_sum_elements(board, line);
		// printf("%s", line);
		ft_add_line_to_board(board, line);
		if (line && ft_strlen(line) > 0)
			free(line);
		line = get_next_line(fd);
	}
	ft_check_board(board);
}
