SRC=test.c
NAME=./libft/libft.a

all:
	gcc -Wall -Werror -Wextra $(SRC) $(NAME)
