INCLUDES_MAC = -Imlx

NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address


MLX_FLAGS_MAC = -Lmlx -lmlx -framework OpenGL -framework AppKit 

SRCS = main.c map.c move.c paint.c checker.c error.c \
	flood_fill.c get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c \
	ft_printf/ft_printf.c ft_printf/ft_printf_ut.c

OBJ = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(INCLUDES_MAC) -c $< -o $@

$(NAME): $(OBJ)
	make -C mlx
	make -C ft_printf
	$(CC) $(OBJ) $(MLX_FLAGS_MAC) -o $(NAME) 

all: $(NAME)

fclean: clean
	rm -rf ft_printf/*.a
	rm -rf $(NAME)

clean:
	make clean -C mlx
	make clean -C ft_printf
	rm -rf *.o
	rm -rf get_next_line/*.o

re: fclean all

.PHONY: all clean fclean re