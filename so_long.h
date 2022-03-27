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

int ft_read_map(char *file);

#endif