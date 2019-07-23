SRC=includes/list.c includes/checkfunc.c includes/setelements.c includes/printing.c includes/setting.c includes/sorting.c includes/reading.c includes/bonusfunc.c includes/checkerrors.c includes/printing2.c\
includes/sorting2.c
NAME=ft_ls
RED=\033[0;31m
LBLUE=\033[1;34m
LGREEN=\033[1;32m
OBJ = $(SRC:.c=.o)

all:$(NAME)

$(NAME):
	@make some -C libft/
	@gcc -Wall -Werror -Wextra -c $(SRC)
	@ar rc libftcomb.a libft/*.o *.o
	@ranlib libftcomb.a
	@gcc -Wall -Werror -Wextra -o ft_ls ft_ls.c libftcomb.a
	@echo "$(LGREEN)Done compiling ft_ls"

clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	@echo "$(LBLUE)Cleaned All .O Files"

fclean:clean
	@rm -f ft_ls
	@rm -f libftcomb.a
	@echo "$(LBLUE)Cleaned librarys and exec"

re:fclean all
