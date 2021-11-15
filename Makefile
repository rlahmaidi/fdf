C=gcc
FLAGS=-Wall -Wextra -Werror
SRC = main.c srcs/*.c srcs/*/*.c
OBJ = main.o
NAME=fdf

all : $(NAME)

$(NAME): $(SRC)
		@$(C) $(FLAGS) $(SRC) -o $(NAME)
	
debug: $(SRC)
		@$(C) -g $(FLAGS) $(SRC) -o $(NAME) -fsanitize=address

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(name)

re:	fclean all