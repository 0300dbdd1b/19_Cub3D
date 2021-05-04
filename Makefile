CC=				gcc

CFLAGS=			-Wall -Wextra -Werror

BUFFER_SIZE=	16

NAME=			cub3D

INCLUDES:=		-I ./includes/ -I ./libft/includes  -I ./minilibX/

FILES=			./srcs/main.c\
				./srcs/game_loop.c\
				./srcs/save_bmp.c\
				./srcs/error/error.c\
				./srcs/structures/struct.c\
				./srcs/structures/data_struct.c\
				./srcs/structures/free_struct.c\
				./srcs/structures/free_data_struct.c\
				./srcs/parser/parser.c\
				./srcs/parser/res_parser.c\
				./srcs/parser/textures_parser.c\
				./srcs/parser/fc_parser.c\
				./srcs/parser/map_parser.c\
				./srcs/parser/get_data.c\
				./srcs/parser/get_textures.c\
				./srcs/parser/get_map.c\
				./srcs/parser/get_pos.c\
				./srcs/parser/check_valid_map.c\
				./srcs/render/print_column.c\
				./srcs/render/find_intersection.c\
				./srcs/render/check_hit.c\
				./srcs/render/render.c\
				./srcs/sprite/sprite.c\
				./srcs/sprite/print_sprite.c\
				./srcs/sprite/find_sprite_col.c\
				./srcs/utils/check_path.c\
				./srcs/utils/rgb_utils.c\
				./srcs/utils/rad_utils.c\
				./srcs/utils/mlx_utils.c\
				./srcs/utils/mlx_img_utils.c\
				./srcs/utils/resize_image.c\
				./srcs/utils/ft_abs.c\
				./srcs/utils/sprite_utils.c\
				./srcs/utils/get_dist.c\
				./libft/srcs/get_next_line/ft_get_next_line_utils.c\
				./libft/srcs/get_next_line/ft_get_next_line.c\
			


OBJ=			$(FILES:.c=.o)

LIB=			./libft/libft.a ./minilibX/libmlx.a -lXext -lX11 -lm 

$(NAME): libft/libft.a minilibX/libmlx.a $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(INCLUDES) $(OBJ) $(LIB)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDES) -D BUFFER_SIZE=$(BUFFER_SIZE) -o $@ $<

all: $(NAME)

clean: 
	@rm -rf $(OBJ)
	make -C ./libft clean

fclean: clean
	@rm -rf $(NAME)
	make -C ./libft fclean
	make -C ./minilibX clean

re: fclean $(NAME)

libft/libft.a:
	make -C ./libft

minilibX/libmlx.a:
	make -C ./minilibX
