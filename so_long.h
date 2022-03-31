#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/errno.h>
# include <errno.h>
# include "libft.h"
# include "gnl/get_next_line.h"
# include <mlx.h>

// typedef struct s_list
// {
// 	int				pos;
// 	int long		num;
// 	struct s_list	*next;
// }	t_list;

typedef struct  s_board {
	int     x;
	int 	y;
	char	type;
	int		is_border;
    int     jug;
    int     coll;
    int     end;
} t_board;

// main.c
void	ft_read_map(char *file, int *x, int *y); 

// read_file.c

// leaks.c
void	leaks();

// free_variables.c
void	free_variables(t_board **board);
void	free_variables_list(char **list);

#endif