/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:41:49 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/26 20:13:33 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53 || keycode == 49)
	{	
		mlx_clear_window(data->mlx, data->mlx_win);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (keycode == 1)
	{
		if ((data->player.x + 1) < (data->cont->y - 1))
		{
			if (data->board[data->player.x + 1][data->player.y].type != '1')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->field,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				data->player.x += 1;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->field,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->dino,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				if (data->board[data->player.x][data->player.y - 1].type == 'C')
					data->cont[0].coll -= 1;
				printf("%d\n", data->cont->coll);			
			}
		}
		else
			write(1, "te has salido\n", 14);
		// d_movement()
	}
	if (keycode == 13)
	{
		if ((data->player.x - 1) > 0)
		{
			if (data->board[data->player.x - 1][data->player.y].type != '1')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->field,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				data->player.x -= 1;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->field,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->dino,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				if (data->board[data->player.x][data->player.y - 1].type == 'C')
					data->cont[0].coll -= 1;
				printf("%d\n", data->cont->coll);
			}
		}
		else
			write(1, "te has salido\n", 14);
		// d_movement()
	}
	if (keycode == 2)
	{
		if ((data->player.y + 1) < (data->cont->x - 1))
		{
			if (data->board[data->player.x][data->player.y + 1].type != '1')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->field,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				data->player.y += 1;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->field,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->dino,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				if (data->board[data->player.x][data->player.y - 1].type == 'C')
					data->cont[0].coll -= 1;
				printf("%d\n", data->cont->coll);			
			}
		}
		else
			write(1, "te has salido\n", 14);
		// d_movement()
	}
	if (keycode == 0)
	{
		if ((data->player.y - 1) > 0)
		{
			if (data->board[data->player.x][data->player.y - 1].type != '1')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->field,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				data->player.y -= 1;
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->field,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				mlx_put_image_to_window(data->mlx, data->mlx_win, data->dino,(data->board[data->player.x][data->player.y].col * data->px), (data->board[data->player.x][data->player.y].row * data->px));
				if (data->board[data->player.x][data->player.y - 1].type == 'C')
					data->cont[0].coll -= 1;
				printf("%d\n", data->cont->coll);
			}
		}
		else
			write(1, "te has salido\n", 14);
		// d_movement()
	}
	return (0);
}
