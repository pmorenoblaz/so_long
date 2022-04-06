/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_variables.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <pmoreno-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 15:36:06 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/04/06 18:38:09 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_variables(t_list **list)
{
	t_list	*aux;

	aux = *list;
	while (*list)
	{
	// 	aux = (*list)->next;
	// 	if ((*list)->comm != NULL)
	// 		free_variables_list((*list)->comm);
		free(*list);
		*list = aux;
	}
	free(*list);
}

void	free_variables_list(char **list)
{
	int		i;

	i = 0;
	while (list[i])
	{
		free(list[i]);
		i++;
	}
	free(list);
}
