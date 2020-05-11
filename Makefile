.PHONY: clean fclean re make all

FILENAMES	= main.c
FILENAMES	+= ft_printf.c
FILENAMES	+= ft_handle_string.c ft_handle_char.c ft_handle_int.c
NAME		= pf

SRC_DIR		= src/
SRCS		= $(addprefix $(SRC_DIR), $(FILENAMES))
OBJS		= $(FILENAMES:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
IFLAGS		= -I./includes/  -I./libft/
LFLAGS		= -L./libft/ -lft
LIBFT		= libft/libft.a

all: $(NAME)

$(NAME):$(OBJS)
	@make -C ./libft
	@$(CC) $(CFLAGS) $(IFLAGS) -c $(SRCS)
	@echo $(OBJS)
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