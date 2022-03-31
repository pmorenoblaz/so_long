/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:05:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/03/31 18:06:53 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
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
	board = malloc(sizeof(t_board *) * (x));
	ft_final_matrix(argv[1], board, x, y);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	free(mlx);
	free(mlx_win);
	
	return (0);
}
