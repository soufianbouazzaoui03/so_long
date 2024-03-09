CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = so_long
B_NAME = so_long_b
LIBFT = "libft/libft.a"
LIBFT_B = "so_long_bonus/libft/libft.a"
B_SRC = so_long_bonus/so_long_bonus.c so_long_bonus/tools_bonus.c so_long_bonus/parsing_bonus.c so_long_bonus/parsing_2_bonus.c so_long_bonus/map_parsing_bonus.c so_long_bonus/moves_bonus.c so_long_bonus/palyermoves_bonus.c so_long_bonus/animation_bonus.c so_long_bonus/checksegs_bonus.c so_long_bonus/free_bonus.c so_long_bonus/destroy_bonus.c so_long_bonus/gnl/get_next_line.c so_long_bonus/gnl/get_next_line_utils.c
B_OBJ = $(B_SRC:%.c=%.o)
SRC = so_long.c tools.c  parsing.c parsing_2.c map_parsing.c moves.c palyermoves.c  checksegs.c free.c destroy.c gnl/get_next_line.c gnl/get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)

all : $(NAME)

bonus : $(B_NAME)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit $(LIBFT) -o $(NAME)

$(B_NAME) : $(B_OBJ)
	make -C so_long_bonus/libft
	$(CC) $(B_OBJ) -lmlx -framework OpenGL -framework AppKit $(LIBFT_B) -o $(B_NAME)

so_long_bonus/%.o : so_long_bonus/%.c so_long_bonus/so_long_bonus.h so_long_bonus/libft/libft.h so_long_bonus/gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o : %.c so_long.h libft/libft.h gnl/get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@


clean :
	rm -rf $(OBJ) $(B_OBJ)
	make -C ./libft clean
	make -C ./so_long_bonus/libft clean

fclean : clean
	rm -rf $(NAME) $(B_NAME)
	make -C ./libft fclean
	make -C ./so_long_bonus/libft fclean

re : fclean all

.PHONY : all bonus clean fclean re