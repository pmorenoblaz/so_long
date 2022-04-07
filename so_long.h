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

typedef struct  s_board {
	int     x;
	int 	y;
	char	type;
	int		is_border;
	int     jug;
    int     coll;
    int     end;
} t_board;

typedef struct s_cont {
	int     jug;
    int     coll;
    int     end;
} t_cont;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
} t_data;

// main.c
t_list	*ft_read_map(char *file, int cont[2]);

// read_file.c
t_list	*ft_read_map(char *file, int cont[2]);

// leaks.c
void	leaks();

// free_variables.c
void	free_variables(t_list **list);
void	free_variables_list(char *list);
void	free_variables_board(t_board ***list, int fil);

// matrix.c
void ft_initialize_pos(t_board *elem);
t_board	ft_add_line_to_lit_list(char c, int fil, int col);
t_board	**ft_final_matrix(t_list **list, int cont[2]);

#endif