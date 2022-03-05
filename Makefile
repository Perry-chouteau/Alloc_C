##
## EPITECH PROJECT, 2022
## B-PSU-400-PAR-4-1-malloc-perry.chouteau
## File description:
## Makefile
##

SRC	=		alloc.c \
			bloc.c

OBJ			=	$(SRC:.c=.o)

CC	=	gcc

CPPFLAGS	=	-iquote ./includes/

CFLAGS		+=	-W -Wall -Wextra -fPIC

NAME		=	libmy_malloc.so

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

debug: CFLAGS+=-g3
debug: re

.PHONY:	all clean fclean re