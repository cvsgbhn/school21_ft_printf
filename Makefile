.PHONY: clean fclean re make all

FILENAMES = main.c
FILENAMES +=  ft_printf.c
NAME =ft_printf

SRCS	=$(addprefix src/, $(FILENAMES))
OBJS_DIR = build/
OBJS	=$(addprefix $(OBJS_DIR), $(FILENAMES:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I includes/
LFLAGS	= -L ./libft/

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME):$(OBJS_DIR) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS) -lft

build/%.o: src/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

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