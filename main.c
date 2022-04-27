/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:05:56 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/27 20:37:49 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	is_player(t_board **board, int i, int j)
{
	if (board[i][j].type == 'P')
		return (1);
	return (0);
}

t_player	where_is_the_player(t_board **board, int x, int y)
{
	int			i;
	int			j;
	t_player	player;

	player.x = -1;
	player.y = -1;
	i = -1;
	while (++i < x)
	{
		j = 0;
		while (j < y)
		{
			if (is_player(board, i, j))
			{
				player.y = j;
				player.x = i;
				break ;
			}	
			j++;
		}
	}
	return (player);
}


int	main(int argc, char **argv)
{
	t_data	data;
	t_list	*list;
	int		cont[2];

	atexit(leaks);
	list = 0;
	data.board = 0;
	data.cont = 0;
	cont[0] = 0;
	cont[1] = 0;
	data.mov_cont = 0;
	if (argc != 2)
	{
		printf("Error en el número de argumentos\n");
		exit (0);
	}
	list = ft_read_map(argv[1], cont);
	data.board = ft_final_matrix(&list, cont);
	data.cont = sum_cont(data.board, cont);
	check_map(data.board, cont);
	check_counters(data.cont);
	data.player = where_is_the_player(data.board, data.cont->y, data.cont->x);
	set_images(&data, cont);
	put_field(data.board, cont[1], cont[0], data);
	replace_field(data.board, cont[1], cont[0], data);
	mlx_key_hook(data.mlx_win, &key_hook, &data);
	mlx_loop(data.mlx);
	free(data.mlx);
	free(data.mlx_win);
	free_variables(&list);
	free_variables_board(data.board, cont[0]);
	return (0);
}
