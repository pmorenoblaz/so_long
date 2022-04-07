/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:05:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/07 20:32:43 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	t_cont	*counters;
	t_list	*list;
	t_board **board;
	int		cont[2];

	atexit(leaks);
	list = 0;
	board = 0;
	counters = 0;
	cont[0] = 0;
	cont[1] = 0;
	if (argc != 2)
	{
		printf("Error en el número de argumentos\n");
		exit (0);
	}
	list = ft_read_map(argv[1], cont);
	board = ft_final_matrix(&list, cont);
	counters = sum_cont(board, cont);
	printf("\nContadores:\nJugadores: %d\nSalidas: %d\nColeccionables: %d\n\n", counters->jug, counters->end, counters->coll);
	check_map_values(board, cont[0], cont[1]);
	check_map_border(board, cont[0], cont[1]);
	free_variables(&list);
	free(*board);
	
	// free_variables_board(&board, cont[0]);
	// print_matrix(board, cont[0], cont[1]);
	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	
	// mlx_loop(mlx);
	// free(mlx);
	// free(mlx_win);
	
	// free_variables_board(board, cont[0], cont[1]);
	return (0);
}
