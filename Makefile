SRC=test.c list.c
NAME=./libft/libft.a

all:
	make some -C libft/
	gcc -Wall -Werror -Wextra -c includes/*.c
	ar rc libftcomb.a libft/*.o list.o
	ranlib libftcomb.a
	gcc -Wall -Werror -Wextra -o ft_ls ft_ls.c libftcomb.a

re:
	gcc -Wall -Werror -Wextra -c includes/*.c
	ar rc libftcomb.a libft/*.o includes/list.o
	ranlib libftcomb.a
	gcc -Wall -Werror -Wextra -o ft_ls ft_ls.c libftcomb.a
