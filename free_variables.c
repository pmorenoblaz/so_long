/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:36:06 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/03/31 18:17:44 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_variables(t_board **board)
{
	t_board	*aux;

	aux = *board;
	while (*board)
	{
	// 	aux = (*board)->next;
	// 	if ((*board)->comm != NULL)
	// 		free_variables_list((*board)->comm);
		free(*board);
		*board = aux;
	}
	free(*board);
}

void	free_variables_list(char **list)
{
	int		i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}
