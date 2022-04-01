#include "so_long.h"

void    ft_sum_elements(t_board **board, char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == 'P')
            board->jug++;
        if (line[i] == 'E')
            board->end++;
        if (line[i] == 'C')
            board->coll++;
        i++;
    }    
}

void    ft_check_board(t_board **board, int *x)
{
    int i;

    i = 0;
    if (board->jug != 1)
    {
        free_variables_list(board);
        exit(0);
    }
    if (board->coll == 0)
    {
        free_variables_list(board);
        exit(0);
    }
    if (board->end != 1)
    {
        free_variables_list(board);
        exit(0);
    }
}

void    ft_check_border(t_board **board, intt x, int y)
{
    int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (i)
				;
			j++;
		}
		i++;
	}
}
