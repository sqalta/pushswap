NAME = push_swap
FLAGS = -Wall -Wextra -g
LIBFT = ./Libft/libft.a
PRINTF_SRC = ./printf/*.c
GNL_SRC = ./gnl/*.c
SRC = ./src/*.c 
CC = gcc

all: $(NAME)

$(NAME): $(SRC) $(LIBFT)
		$(CC) $(FLAGS) $(SRC) $(LIBFT) $(PRINTF_SRC) $(GNL_SRC) -o $(NAME)
$(LIBFT):
	make -C ./Libft
	make bonus -C ./Libft

$(PRINTF_SRC):
	make -C ./printf

clean:

fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re: fclean all

git:
	git add .
	git status
	git commit -m "not_finished"
	git push

.PHONY: clean fclean re