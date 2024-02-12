CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
LIBFT = "./libft/libft.a"
SRC = so_long.c tools.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ) libfta
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $@ $(LIBFT)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBFT)

libfta :
	make -C ./libft

clean :
	rm -rf $(OBJ)
	make -C ./libft clean

fclean : clean
	rm -rf $(NAME)
	make -C ./libft fclean