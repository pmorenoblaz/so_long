/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:26:57 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/03/29 17:58:02 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;

	atexit(leaks);
	if (argc != 2)
	{
		printf("Error en el número de arguentos\n");
		exit (0);
	}
	ft_read_map(argv[1]);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	free(mlx);
	free(mlx_win);
	
	return (0);
}
