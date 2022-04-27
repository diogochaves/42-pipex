# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 00:09:49 by dchaves-          #+#    #+#              #
#    Updated: 2022/03/28 01:31:47 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PATH VARIABLES
INC_PATH	:=	./inc/
LIB_PATH	:=	./lib/
OBJ_PATH	:=	./obj/
SRC_PATH	:=	./src/
LIBFT_PATH	:=	$(LIB_PATH)libft/bin/

# COMPILATION
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror
DEBUG		:=	-g

# BASH COMMANDS
RM 			:=	rm -f
VALGRIND	:=	valgrind --leak-check=full --show-leak-kinds=all \
				--track-origins=yes --trace-children=yes #--track-fds=yes

# FILES
NAME		:=	pipex
HEADER		:=	$(INC_PATH)pipex.h \
				$(INC_PATH)macros.h \
				$(INC_PATH)structs.h

SRC_FILES 	:=	main.c \
				exit.c \
				files.c \
				init.c

SOURCES		:=	$(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ_FILES	:=	$(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS 	:=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

all:			libft $(NAME)

# -> creates executable
$(NAME):		$(OBJECTS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -lmlx -lXext -lX11 -lm -L $(LIBFT_PATH) -lft

# -> creates object files inside ./obj/
$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(HEADER) | path
				$(CC) $(CFLAGS) $(DEBUG) -I $(INC_PATH) -c $< -o $@

libft:
				make -C $(LIB_PATH)libft

path:
				mkdir -p $(OBJ_PATH)

clean:
				$(RM) $(OBJECTS)

fclean:			clean
				$(RM) $(NAME)
				make fclean -C $(LIB_PATH)libft

re:				fclean all

run:
	./$(NAME) infile "wc -l" wc outfile

val:	
				$(VALGRIND) ./$(NAME) infile "wc -l" wc outfile

.PHONY: 		all clean fclean re libft path run val
