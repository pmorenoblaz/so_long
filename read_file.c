/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:01:35 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/06 19:44:23 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_read_map(char *file)
{
	int		fd;
	char	*line;
	int		pos[3];
	t_list *aux;

	fd = open(file, O_RDONLY);
	pos[0] = 0;
	line = get_next_line(fd);
	pos[1] = ft_strlen(line);
	aux = 0;
	while (line)
	{
		pos[2] = ft_strlen(line);
		if (pos[1] != pos[2])
		{
			free(line);
			free_variables(&aux);
			close(fd);
			exit (0);
		}
		ft_lstadd_back(&aux, ft_lstnew(line));
		printf("%s", line);
		if (line && ft_strlen(line) > 0)
			free(line);
		line = get_next_line(fd);
		pos[0]++;
	}
	
	free(line);
	close(fd);
	return (aux);
}

// void	ft_add_line_to_lit_list(t_list **lit_list, char *line, int col, int fil)
// {
// 	int i;

// 	i = 0;
// 	while (i < col)
// 	{
// 		lit_list[fil][i].x = fil;
// 		lit_list[fil][i].y = i;
// 		lit_list[fil][i].type = line[i];
// 		lit_list[fil][i].is_border = 0;
// 		if (line[i] == '1')
// 			lit_list[fil][i].is_border = 1;
// 		i++;
// 	}
// }



t_board	*ft_final_matrix(t_list **list)
{
	list = 0;
	return 0;
}
