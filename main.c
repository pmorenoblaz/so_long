/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:05:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/22 16:58:39 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_board **matrix, int row, int col, t_data  data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < col)
	{
		j = 0;
		while (j < row)
		{
			mlx_put_image_to_window(data.mlx, data.mlx_win, data.field,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
			j++;
		}
	}
}
	
void	print_img2(t_board **matrix, int row, int col, t_data  data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < col)
	{
		j = 0;
		while (j < row)
		{
			if (matrix[i][j].type == '1')
			{
				if (i == 0 || j == 0 || i == col - 1 || j == row - 1)
					mlx_put_image_to_window(data.mlx, data.mlx_win, data.border,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
				else
					mlx_put_image_to_window(data.mlx, data.mlx_win, data.obs,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
			}
			if (matrix[i][j].type == 'P')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.dino,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
			if (matrix[i][j].type == 'C')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.food,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
			if (matrix[i][j].type == 'E')
				mlx_put_image_to_window(data.mlx, data.mlx_win, data.end,(matrix[i][j].col * data.px), (matrix[i][j].row * data.px));
			j++;
		}
	}
}

void	set_images(t_data *data, int cont[2])
{
	data->px = 80;
	data->mlx = mlx_init();
	data->field =  mlx_xpm_file_to_image(data->mlx,"./img/field.xpm", &data->px, &data->px);
	data->dino =  mlx_xpm_file_to_image(data->mlx,"./img/1.xpm", &data->px, &data->px);
	data->food =  mlx_xpm_file_to_image(data->mlx,"./img/polloesc2.xpm", &data->px, &data->px);
	data->border = mlx_xpm_file_to_image(data->mlx,"./img/border.xpm", &data->px, &data->px);
	data->obs = mlx_xpm_file_to_image(data->mlx,"./img/obs2.xpm", &data->px, &data->px);
	data->end = mlx_xpm_file_to_image(data->mlx,"./img/cave.xpm", &data->px, &data->px);
	data->mlx_win = mlx_new_window(data->mlx, data->px * cont[1], data->px * cont[0], "so_long");
}



int	main(int argc, char **argv)
{
	// void	*mlx;
	// void	*mlx_win;
	t_data	data;
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

	set_images(&data, cont);
	print_img(board, cont[1], cont[0], data);
	print_img2(board, cont[1], cont[0], data);
	mlx_key_hook(data.mlx_win, &key_hook, &data);


	mlx_loop(data.mlx);
	free(data.mlx);
	free(data.mlx_win);
	
	free_variables(&list);
	free_variables_board(board, cont[0]);
	return (0);
}
