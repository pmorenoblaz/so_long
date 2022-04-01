/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:01:35 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/01 19:05:33 by pmoreno-         ###   ########.fr       */
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

void	ft_add_line_to_board(t_board **board, char *line, int pos, int col)
{
	int i;

	i = 0;
	while (i < pos[1])
	{
		board[col][i]->x = x;
		board[col][i]->y = i;
		board[col][i]->type = line[i];
		board[col][i]->is_border = 0;
		if (line[i] == '1')
			board[col][i]->is_border = 1;
		i++;
	}
}

void	ft_final_matrix(char *file, t_board **board, int *x, int *y)
{
	int		fd;
	char	*line;
	int		pos[2];

	fd = open(file, O_RDONLY);
	pos[0] = 0;
	while (pos[0] < x)
	{
		line = get_next_line(fd);
		pos[1] = 0;
		board[pos[0]] = malloc(sizeof(t_board) * (*y));
		ft_sum_elements(board, line);
		ft_add_line_to_board(board, line, pos[1], &x);
		if (line && ft_strlen(line) > 0)
			free(line);
	}
	close(fd);
	ft_check_board(board);
	ft_check_border(board, x, y);
}
