NAME		= cub3d

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
				exec/raycast.c \
				exec/visualize.c \

OBJS        = $(SRCS:.c=.o)

all: pre_make $(NAME)

$(NAME): $(CUB3D)
	$(CC) $(CFLAGS) $(LINKS_LIBRARY) -lmlx -framework OpenGL -framework AppKit -fsanitize=address $^ -o $@

$(CUB3D): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_HEADER) -c $^ -o $@ -g

clean: pre_clean
	$(RM) $(OBJS)
	$(RM) $(CUB3D)

fclean: clean pre_fclean
	$(RM) $(NAME)

re: fclean all

pre_make:
	make -C $(LIBFT_DIR)

pre_clean:
	make clean -C $(LIBFT_DIR)

pre_fclean:
	make fclean -C $(LIBFT_DIR)
