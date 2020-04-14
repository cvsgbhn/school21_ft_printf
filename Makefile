.PHONY: clean fclean re make all

FILENAMES = main.c
FILENAMES +=  ft_printf.c
NAME =ft_printf

SRCS	=$(addprefix src/, $(FILENAMES))
OBJS	=$(addprefix build/, $(FILENAMES:.c=.o))
OBJS_DIR = build/

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I includes/
LFLAGS	= -L ./libft/

all: $(OBJS) $(NAME)

$(NAME):$(OBJS_DIR) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS) -lft

build/%.o: src/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./libft
	@make clean -C ./libft

clean:
	@rm -rf build/

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

build:
	@mkdir build/