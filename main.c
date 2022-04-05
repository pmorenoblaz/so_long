/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:05:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/05 20:43:38 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data *data;
	int		x;
	int		y;
	t_board	**board;

	atexit(leaks);
	if (argc != 2)
	{
		printf("Error en el número de argumentos\n");
		exit (0);
	}
	x = 0;
	ft_read_map(argv[1], &x, &y);
	board = malloc(sizeof(t_board *) * (x + 1));
	// system("leaks so_long");
	ft_final_matrix(argv[1], board, &x, &y);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
	mlx_loop(data->mlx);
	free(data->mlx);
	free(data->mlx_win);
	
	return (0);
}
