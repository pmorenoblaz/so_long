/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:05:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/08 19:27:52 by pmoreno-         ###   ########.fr       */
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
	check_map(board, cont);
	check_counters(counters);
	free_variables(&list);
	free(*board);
	// system("leaks so_long");
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
