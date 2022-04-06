/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:01:35 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/06 20:45:00 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_read_map(char *file, int cont[2])
{
	int		fd;
	char	*line;
	int		len;
	t_list *aux;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	cont[1] = ft_strlen(line) - 1;
	aux = 0;
	while (line)
	{
		len = ft_strlen(line) - 1;
		if (cont[1] != len)
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
		cont[0]++;
	}
	free(line);
	close(fd);
	return (aux);
}

void ft_initialize_pos(t_board *elem)
{
	elem->x = -1;
	elem->y = -1;
	elem->is_border = 0;
	elem->type = 'N';
	elem->coll = 0;
	elem->end = 0;
	elem->jug = 0;	
}

t_board	ft_add_line_to_lit_list(char c, int fil, int col)
{
	t_board elem;

	ft_initialize_pos(&elem);
	elem.x = fil;
	elem.y = col;
	elem.type = c;
	if (c == '1')
		elem.is_border = 1;
	else if(c == 'C')
		elem.coll++;
	else if(c == 'E')
		elem.end++;
	else if(c == 'P')
		elem.jug++;
	return elem;
}



t_board	**ft_final_matrix(t_list **list, int cont[2])
{
	t_board **board;
	t_list	*aux;
	int		i;
	int		j;
	
	i = -1;
	aux = (*list);
	board = malloc(sizeof(t_board *) * (cont[0] + 1));
	while (++i < cont[0])
	{
		aux = aux->next;
		j = 0;
		board[i] = malloc(sizeof(t_board) * (cont[1] + 1));
		while (j < cont[1])
		{
			board[i][j] = ft_add_line_to_lit_list(aux->content[j], i, j);
			j++;
		}
		i++;
		
	}
	
	return board;
}
