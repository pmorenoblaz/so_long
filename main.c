/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:05:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/20 19:22:47 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
	
int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	t_data	data;
	t_cont	*counters;
	t_list	*list;
	t_board **board;
	int		px;
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

	data.mlx = mlx_init();
	px = 80;
	data.field =  mlx_xpm_file_to_image(data.mlx,"./img/field.xpm", &px, &px);
	// data.dino =  mlx_xpm_file_to_image(data.mlx,"./img/polloesc2.xpm", &px, &px);
	// data.food =  mlx_xpm_file_to_image(data.mlx,"./img/besc2.xpm", &px, &px);
	data.mlx_win = mlx_new_window(data.mlx, px * cont[1], px * cont[0], "so_long");
	
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	
	mlx_loop(data.mlx);
	// free(data.mlx);
	// free(data.mlx_win);
	
	
	
	free_variables(&list);
	// free(counters);
	free_variables_board(board, cont[0]);
	return (0);
}
