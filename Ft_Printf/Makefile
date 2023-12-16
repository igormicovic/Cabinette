NAME = libftprintf.a

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

CC = cc 

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

test: $(NAME)
	$(CC) $(CFLAGS) $(NAME) main.c
	make clean
	clear
	./a.out

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f a.out

re: fclean $(NAME)

.PHONY: all clean fclean re
