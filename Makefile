CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = so_long
LIBFT = "./libft/libft.a"
SRC = so_long.c tools.c  parsing.c parsing_2.c map_parsing.c moves.c palyermoves.c animation.c checksegs.c enemy.c enemy_moves.c free.c destroy.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ) libfta
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME) -g

%.o : %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

libfta :
	make -C ./libft

clean :
	rm -rf $(OBJ)
	make -C ./libft clean

fclean : clean
	rm -rf $(NAME)
	make -C ./libft fclean

re : fclean all