SRC = main.c gnl/get_next_line_utils.c gnl/get_next_line.c ft_strncmp.c parsing.c ft_isdigit.c ft_split.c
OBJ = $(SRC: .c=.o)
HDRS = cub.h
NAME = cub
RM      = rm -f
CC      = cc
FLAGS   = -Wall -Wextra -Werror

all: $(NAME)


%.o : %.c
	$(CC) -c -o $@ $<

$(NAME): $(OBJ) $(HDRS)

	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)


fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re