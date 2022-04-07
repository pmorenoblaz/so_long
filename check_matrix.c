/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_board.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 19:59:43 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/07 20:03:12 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_cont *sum_cont(t_board **board, int cont[2])
{
	int		i;
	int		j;
	t_cont	*aux;

	i = -1;
	
	aux = malloc(sizeof(t_cont));
	aux->jug = 0;
	aux->coll = 0;
	aux->end = 0;
	
	while (++i < cont[0])
	{
		j = 0;
		while (j < cont[1])
		{
			if(board[i][j].type == 'C')
				aux->coll++;
			else if(board[i][j].type == 'E')
				aux->end++;
			else if(board[i][j].type == 'P')
				aux->jug++;
			j++;
		}
	}
	return (aux);
}

void	check_map_values(t_board **board, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (board[i][j].type != 'C' &&
					board[i][j].type != 'P' &&
						board[i][j].type != 'E' &&
							board[i][j].type != '0' &&
								board[i][j].type != '1')
                                {
				                    printf("Valores mal\n");
                                    break;
                                }
			j++;
		}
		i++;
	}
}

void	check_map_border(t_board **board, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (i == 0 || j == 0)
                if (board[i][j].type != '1')
                {
                    printf("Borde de arriba o primera columna mal\n");
                    break;
                }
			if (i == x - 1 || j == y - 1)
                if (board[i][j].type != '1')
                {
                    printf("Borde de abajo o última columna mal\n");
                    break;
                }
                j++;
		}
		i++;
	}
}
