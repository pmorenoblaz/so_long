/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 17:59:08 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/03/29 17:59:11 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	t_board	board;

	atexit(leaks);
	if (argc != 2)
	{
		printf("Error en el número de arguentos\n");
		exit (0);
	}
	ft_read_map(argv[1], &x, &y);
	board->board = malloc(sizeof(char))
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	free(mlx);
	free(mlx_win);
	
	return (0);
}
