##
## EPITECH PROJECT, 2022
## bsq
## File description:
## Makefile
##

SRC				=	source/main_file.c\
					source/generator.c\
					source/solver.c\
					source/useful.c\
					source/error.c\
					source/get_size.c\
					source/solve_arr.c\
					source/solving_arr.c\
					source/free_if.c

OBJ				=	$(SRC:.c=.o)

CPPFLAGS		=	-Wall -Wextra -I./include/

MYH				=	include/my.h

DIR				=	-L./lib/ -lmy

LIBNAME			=	libmy.a

NAME			=	bsq

all: compil

compil : $(OBJ)
	$(MAKE) -C ./lib/my
	gcc -o $(NAME) $(OBJ) $(DIR) $(LIB)

debug:	CFLAGS += -g3 -Wall -Wextra
debug:	re

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C ./lib/my

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./lib/my

re: fclean all

.PHONY: all makelib clean fclean re
