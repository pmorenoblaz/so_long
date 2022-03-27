/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 11:26:57 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/03/27 11:29:52 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_read_map(char *file)
{
    int			fd;
	char		*line;
	int			pos[2];
    int         cont;

    pos[1] = 0;
    cont = 0;
	fd = open(file, O_RDONLY);
    line = get_next_line(fd);
    pos[0] = ft_strlen(line);
	while (line)
	{
        pos[1]++;
        cont = ft_strlen(line);
        if (cont != pos[0])
        {
            free(line);
            return (0);
        }
        printf("line %i=>%s", pos[1] + 1, line);
		if (line && ft_strlen(line) > 0)
			free(line);
		line = get_next_line(fd);
	}
    free(line);
    close(fd);
    return (1);
}


int	main(int argc, char **argv)
{
    if (argc != 2)
        printf("Error en el número de arguentos\n");
    argv = 0;
	return (0);
}