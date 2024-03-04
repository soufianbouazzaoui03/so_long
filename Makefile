CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = so_long
LIBFT = "./libft/libft.a"
SRC = so_long_bonus.c tools_bonus.c parsing_bonus.c parsing_2_bonus.c map_parsing_bonus.c moves_bonus.c palyermoves_bonus.c animation_bonus.c checksegs_bonus.c free_bonus.c destroy_bonus.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ) libfta
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME) 

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