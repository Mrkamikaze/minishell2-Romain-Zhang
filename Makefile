##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

SRC	=	main.c				\
		my_strcmp.c			\
		my_printf/display.c		\
		my_printf/my_put_hex_nbrup.c	\
		my_printf/my_put_unsigned_nbr.c	\
		my_printf/my_put_nbr.c		\
		my_printf/my_putstr.c		\
		my_printf/my_put_float.c	\
		my_printf/my_putchar.c		\
		my_printf/my_strlen.c		\
		my_str_to_word_array.c		\
		display_word_array.c		\
		segmentation.c			\
		env_function.c			\
		unsetenv.c			\
		setenv.c			\
		cd.c				\
		native_commands.c		\
		error_messages.c		\
		concat.c			\
		my_pipe.c			\
		formatter.c

NAME	=       mysh

OBJ	=	$(SRC:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		gcc -o $(NAME) $(SRC) -lncurses -g3

clean   :
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	 re fclean clean all
