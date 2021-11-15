C=gcc
FLAGS=-Wall -Wextra -Werror
SRC = main.c srcs/*.c srcs/*/*.c
OBJ = main.o
NAME=fdf
DEP = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME): $(SRC)
		@$(C) $(FLAGS) $(SRC) $(DEP) -o $(NAME)
	
debug: $(SRC)
		@$(C) -g $(FLAGS) $(SRC) $(DEP) -o $(NAME) -fsanitize=address

clean:
		@rm -rf $(OBJ)

fclean: clean
		@rm -rf $(name)

re:	fclean all