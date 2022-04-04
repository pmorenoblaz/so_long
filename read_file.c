/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:01:35 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/04 15:26:53 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_read_map(char *file, int *x, int *y)
{
	int		fd;
	char	*line;
	int		len;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	*y = ft_strlen(line);
	while (line)
	{
		(*x)++;
		len = ft_strlen(line);
		if (len != (*y))
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

void	ft_add_line_to_board(t_board **board, char *line, int col, int fil)
{
	int i;

	i = 0;
	while (i < col)
	{
		board[fil][i].x = fil;
		board[fil][i].y = i;
		board[fil][i].type = line[i];
		board[fil][i].is_border = 0;
		if (line[i] == '1')
			board[fil][i].is_border = 1;
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
	while (pos[0] < (*x))
	{
		system("leaks so_long");
		line = get_next_line(fd);
		pos[1] = 0;
		system("leaks so_long");
		board[pos[0]] = malloc(sizeof(t_board) * (*y));
		
		//ft_sum_elements(board, line);
		ft_add_line_to_board(board, line, pos[1], pos[0]);
		// if (line && ft_strlen(line) > 0)
		free(line);
		pos[0]++;
	}
	close(fd);
	//ft_check_board(board);
	//ft_check_border(board, x, y);
}
