CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SRC_PATH = ./
OBJ_PATH = ./obj/
INC_PATH = ./includes
NAME = fillit
SRC_NAME = check.c main.c algo.c ft_fillmap.c map.c move_up_left.c \
		ft_stock.c ft_strlen.c ft_sqrt.c ft_putchar.c ft_putstr.c
TMP = tmp.txt
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I, $(INC_PATH))

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "Compilation OBJ done !"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@echo "Compilation EXE done !"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

r : run

run :
	@echo "Running program : $(NAME)"
	./$(NAME) | less

clean:
	@rm -rfv $(OBJ_PATH)
	@rm -f $(TMP)
	@echo "Clean !"

fclean : clean
	@rm -fv $(NAME)

re : clean all
