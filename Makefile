NAME		= cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar
ARFLAGS		= rcs

INCLUDES_HEADER  = -I$(LIBFT_DIR) -I header
LINKS_LIBRARY    = -L$(LIBFT_DIR) -lft

LIBFT_DIR		 = ./libft
CUB3D		 = cub3D.a

SRCS		= cub3D.c \
				utils/all_utils.c \

OBJS        = $(SRCS:.c=.o)

all: pre_make $(NAME)

$(NAME): $(CUB3D)
	$(CC) $(CFLAGS) $(LINKS_LIBRARY) $^ -o $@ -g

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