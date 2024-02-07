NAME		= cub3D
NAME_BONUS	= cub3D_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar
ARFLAGS		= rcs

INCLUDES_HEADER  = -I$(LIBFT_DIR) -I header
LINKS_LIBRARY    = -L$(LIBFT_DIR) -lft

LIBFT_DIR		 = ./libft
CUB3D		 = cub3d.a

SRCS		= cub3d.c \
				all_utils.c \
				exec/cardinal_points.c \
				exec/keyhook.c \
				exec/mlx_utils.c \
				exec/raycast.c \
				exec/visualize.c \
				parse/parse.c \
				parse/file_convert/ft_convert_file_to_str.c \
				parse/file_convert/ft_convert_str_to_map_data.c \
				parse/game_valid_make/valid_make_handling.c \
				parse/game_valid_make/valid_make_utils.c \
				parse/game_valid_make/ft_texture_img_creat.c \
				parse/game_valid_make/ft_texture_rgb_creat.c \
				parse/game_valid_make/ft_map_info_creat.c \
				parse/game_valid_make/ft_map_valid_check.c \

SRCS_BONUS	= cub3d_bonus.c \
				all_utils_bonus.c \
				exec/cardinal_points_bonus.c \
				exec/keyhook_bonus.c \
				exec/mlx_utils_bonus.c \
				exec/raycast_bonus.c \
				exec/visualize_bonus.c \
				parse/parse_bonus.c \
				parse/file_convert/ft_convert_file_to_str_bonus.c \
				parse/file_convert/ft_convert_str_to_map_data_bonus.c \
				parse/game_valid_make/valid_make_handling_bonus.c \
				parse/game_valid_make/valid_make_utils_bonus.c \
				parse/game_valid_make/ft_texture_img_creat_bonus.c \
				parse/game_valid_make/ft_texture_rgb_creat_bonus.c \
				parse/game_valid_make/ft_map_info_creat_bonus.c \
				parse/game_valid_make/ft_map_valid_check_bonus.c \

OBJS        = $(SRCS:.c=.o)
OBJS_BONUS  = $(SRCS_BONUS:.c=.o)

all: pre_make $(NAME)

bonus: pre_make $(NAME_BONUS)

$(NAME): $(CUB3D)
	$(CC) $(CFLAGS) $(LINKS_LIBRARY) -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(NAME_BONUS): $(CUB3D)
	$(CC) $(CFLAGS) $(LINKS_LIBRARY) -lmlx -framework OpenGL -framework AppKit $^ -o $@

$(CUB3D): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_HEADER) -c $^ -o $@ -g

clean: pre_clean
	$(RM) $(OBJS)
	$(RM) $(CUB3D)

fclean: clean pre_fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)

re: fclean all

pre_make:
	make -C $(LIBFT_DIR)

pre_clean:
	make clean -C $(LIBFT_DIR)

pre_fclean:
	make fclean -C $(LIBFT_DIR)
