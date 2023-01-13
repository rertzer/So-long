CC = gcc
FLAGS = -Wall -Wextra -Werror

TARGET = so_long

LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a 

MLX_PATH = minilibx-linux
MLX = $(MLX_PATH)/libmlx.a

LIBS_PATH = /usr/include

SOURCES = bermap.c \
	check.c\
	cep.c\
	exit.c\
	fifo.c\
	helpers.c\
	init.c\
	main.c\
	path.c\
	game_events.c\
	game_init.c\
	map_draw.c\
	next_frame.c\
	pirate_pos_helper.c\
	pirate_animate.c\
	parrots.c\
	crab_init.c\
	crab_helper.c\
	crab_move.c\
	counter.c


OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(TARGET): $(LIBFT) $(MLX) $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)  $(LIBFT) $(MLX) -L$(LIBS_PATH) -lXext -lX11 -lm

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH) -f Makefile.gen all

clean:
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) -f Makefile.gen clean
	rm -f $(OBJECTS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re ft mlx
