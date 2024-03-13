NAME = get_next_line.a

SRC = get_next_line.c\
	get_next_line_utils.c\

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -D BUFFER_SIZE=42

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

test: all
	$(CC) main.c get_next_line.a
	./a.out
	@rm a.out

clean:
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:	all clean fclean re