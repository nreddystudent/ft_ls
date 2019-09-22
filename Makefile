SRC_NAME=list.c checkfunc.c setelements.c printing.c setting.c sorting.c reading.c bonusfunc.c checkerrors.c printing2.c sorting2.c
NAME=ft_ls
RED=\033[0;31m
LBLUE=\033[1;34m
LGREEN=\033[1;32m
FLAGS = -Wall -Werror -Wextra
LIBFT_PATH = ./libft/
SRC_PATH = ./includes/
OBJ = $(SRC:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
all:$(NAME)

$(NAME):$(OBJ)
	@make -C libft/	
	@gcc $(FLAGS) $(OBJ) -L $(LIBFT_PATH) -lft -o $(NAME)

$(SRC_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@
	@echo "$(LGREEN)Done compiling $(NAME)"

clean:
	@make clean -C libft/
	@rm -f $(OBJ)
	@echo "$(LBLUE)Cleaned All .O Files"

fclean:clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@rm -f libftcomb.a
	@echo "$(LBLUE)Cleaned librarys and exec"

re:fclean all
