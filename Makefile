SRCS	= main.c

LIBFT_PATH = libft/

OBJS	= $(SRCS:.c=.o)

NAME	= so_long

CFLAGS	= -Wall -Werror -Wextra 

GCC	= gcc

RM	= rm -f

all:		$(NAME)

.c.o:
	$(GCC) $(CFLAGS)  -Imlx -c $< -o $@ -I$(LIBFT_PATH)

$(NAME):	$(OBJS)
	@make -C $(LIBFT_PATH)
	$(CC) -o $(NAME) $(OBJS) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I./libft -L./libft -lft

clean:		
	$(RM) $(OBJS)
	make -C $(LIBFT_PATH) clean

fclean:		clean
		$(RM) $(NAME)
		make -C $(LIBFT_PATH) fclean 

re:		fclean all

.PHONY:		all clean fclean re 