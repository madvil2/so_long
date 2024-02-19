NAME :=				so_long

SRC_PATH :=			srcs/
INC_PATH :=			includes/
OBJ_PATH :=			.obj/
LIB_PATH :=			libft/
MLX_PATH :=			mlx_linux/

CC :=				cc
CFLAGS :=			-g -Wall -Werror -Wextra
IFLAGS :=			-I $(INC_PATH) -I $(LIB_PATH) -I $(MLX_PATH)
LFLAGS :=			-L $(LIB_PATH) -lft -L $(MLX_PATH) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

HFILES :=			so_long
FILES :=			main\
					utils\
					hooks\
					parse\
					validate\
					game\
					flood_fill\
					enemies_move\
					enemies_spawn\
					player
LIB :=				$(LIB_PATH)libft.a
MLX :=				$(MLX_PATH)libmlx_Linux.a

HDRS :=				$(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS :=				$(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS :=				$(SRCS:$(SRC_PATH)%.c=$(OBJ_PATH)%.o)

all: $(NAME)

$(NAME): $(LIB) $(MLX) $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)

$(LIB):
	git clone git@github.com:madvil2/libft.git $(LIB_PATH);
	$(MAKE) -C $(dir $@) $(notdir $@)

$(MLX):
	git clone https://github.com/42Paris/minilibx-linux.git $(MLX_PATH)
	$(MAKE) -C $(MLX_PATH)

$(OBJS): $(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HDRS)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C $(LIB_PATH)
	make clean -C $(MLX_PATH)

fclean: mfclean
	rm -rf $(LIB_PATH)
	rm -rf $(MLX_PATH)

re: fclean all

mclean:
	rm -f $(OBJS)

mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)

mre: mfclean all

.PHONY: all clean fclean re mclean mfclean mre
