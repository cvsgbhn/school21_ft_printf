.PHONY: clean fclean re make all

FILENAMES	= main.c
FILENAMES	+= ft_printf.c
FILENAMES	+= ft_handle_string.c
NAME		= ft_printf

SRC_DIR		= src/
SRCS		= $(addprefix $(SRC_DIR), $(FILENAMES))
OBJS		= $(addprefix $(SRC_DIR), $(FILENAMES:.c=.o))

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I includes/
LFLAGS		= -L ./libft/
LIBFT		= libft/libft.a

all: $(NAME)

$(NAME):$(OBJS)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(IFLAGS) -c $(CS)
	@$(CC) $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)

%.o: src/%.c | build
	@$(CC) $(CFLAGS) -c $< -o $@

re: fclean all

lib:
	@make -C ./libft

clean:
	@rm -rf build/
	@make clean -C ./libft

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

build:
	@mkdir build/