/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:51:28 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/07 18:49:39 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	print_matrix(t_board **matrix, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	printf("Matrix:\n");
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			printf("%c", matrix[i][j].type);
			j++;
		}
		printf("\n");
		i++;
	}
}

t_board	**ft_final_matrix(t_list **list, int cont[2])
{
	t_board **board;
	t_list	*aux;
	int		i;
	int		j;
	
	i = -1;
	aux = *list;
	// printf("%s\n", (*list)->content);
	board = malloc(sizeof(t_board *) * (cont[0] + 1));
	while (++i < cont[0])
	{
		aux = aux->next;
		// printf("%s\n", aux->content);
		j = 0;
		board[i] = malloc(sizeof(t_board) * (cont[1] + 1));
		while (j < cont[1])
		{
			board[i][j] = ft_add_line_to_lit_list(aux->content[j], i, j);
			// printf("%c", aux->content[j]);
			j++;
		}
		printf("\n");
		i++;
	}
	// print_matrix(board, cont[0], cont[1]);
	return board;
}