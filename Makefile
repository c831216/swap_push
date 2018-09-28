CC = gcc
NAME = checker
NAME2 = push_swap
FLAGS = -Wall -Werror -Wextra -g
SRC =	./checker.c\
		#./functions.c\
		#./functions1.c\
		#./functions2.c\
		#./functions3.c\
		#./functions4.c\
		#./functions5.c

SRC2 =	#./push_swap.c\
		#./functions.c\
		#./functions1.c\
		#./functions2.c\
		#./functions3.c\
		#./functions4.c\
		#./functions5.c

HEADERS = ./*.h
LIBFT = ./libft
OBJ = $(SRCS:.c=.o)

all: NAME

NAME:
	@ make -C ./libft
	@ $(CC) -o $(NAME) $(FLAGS) $(SRC) -L $(LIBFT) -lft
	@#@ $(CC) -o $(NAME2)  $(FLAGS) $(SRC2) -L $(LIBFT) -lft
	@ echo "Compiled successfully!"

clean:
	@ make -C ./libft/ clean
	@ echo "Objects Removed!"

fclean: clean
	@ make -C ./libft/ fclean
	@ rm -f *.a
	@ echo "Removed All!"

re: fclean all

norm:
	@ norminette ./*.h
	@ norminette ./*.c
	@ norminette ./libft/*.c
	@ norminette ./libft/*.h

.PHONY: all clean fclean re norm
