/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 12:01:35 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/07 18:46:41 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_list(t_list **list)
{
	t_list *aux;

	aux = (*list);
	while (aux)
	{
		printf("%s", aux->content);
		aux = aux->next;
	}
}

t_list	*ft_read_map(char *file, int cont[2])
{
	int		fd;
	char	*line;
	int		len;
	t_list *aux;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	cont[1] = ft_strlen(line) - 1;
	aux = 0;
	while (line)
	{
		len = ft_strlen(line) - 1;
		if (cont[1] != len)
		{
			free(line);
			free_variables(&aux);
			close(fd);
			exit (0);
		}
		ft_lstadd_back(&aux, ft_lstnew(line));
		// free(line);
		line = get_next_line(fd);
		cont[0]++;
	}
	// free(line);
	close(fd);
	print_list(&aux);
	return (aux);
}
