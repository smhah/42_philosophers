FLAGS = -Wall -Wextra -Werror# -g -fsanitize=address

NAME = philo

SRC = *.c

all : $(NAME)

$(NAME) : $(NAMELIB)
	gcc $(FLAGS) $(SRC) -o $(NAME)

fclean :
	rm -f *.a
	rm -f $(NAME)

re : fclean all