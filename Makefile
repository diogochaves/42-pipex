# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchaves- <dchaves-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 00:09:49 by dchaves-          #+#    #+#              #
#    Updated: 2022/03/23 00:22:16 by dchaves-         ###   ########.fr        #
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
VALGRIND	:=	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

# FILES
NAME		:=	pipex
HEADER		:=	$(INC_PATH)pipex.h

SRC_FILES 	:=	main.c

SOURCES		:=	$(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ_FILES	:=	$(patsubst %.c, %.o, $(SRC_FILES))
OBJECTS 	:=	$(addprefix $(OBJ_PATH), $(OBJ_FILES))

all:			libft $(NAME)

# -> creates executable
$(NAME):		$(OBJECTS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -lmlx -lXext -lX11 -lm -L $(LIBFT_PATH) -lft

# -> creates object files inside ./obj/
$(OBJ_PATH)%.o:	$(SRC_PATH)%.c $(HEADER) | path
				$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

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
	./$(NAME)

val:	
				$(VALGRIND) ./$(NAME)

.PHONY: 		all clean fclean re libft path run val
