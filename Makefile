# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbourand <mbourand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/14 15:50:28 by mbourand          #+#    #+#              #
#    Updated: 2020/03/02 15:36:49 by mbourand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRC_PATH= srcs/
OBJ_PATH= objs/

SRC_NAME= main.c prompt.c cwd.c command.c tokens.c utils.c
OBJ_NAME= $(SRC_NAME:.c=.o)

INC= -I incs/ -I libft/ -I libft/printf/ -I libft/get_next_line/
SRC= $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ= $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIB= -L libft/ -lft
DEF= \033[0m
RED= \033[31;1m
GRN= \033[32;1m
YEL= \033[33;1m

.PHONY: all re clean fclean

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)[minishell] : $(DEF)Compilation..."
	@make -C libft
	@gcc $(CFLAGS) -fsanitize=address -g -o $(NAME) $(OBJ) $(INC) $(LIB)
	@echo "$(RED)[minishell] : $(DEF)Compilation                 $(GRN)[OK]$(DEF)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED)[minishell] :$(DEF) Compiling $@"
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@make -C libft clean
	@rm -rf $(OBJ_PATH)
	@echo "$(RED)[minishell] : $(DEF)Cleaning           $(GRN)[OK]$(DEF)"

fclean: clean
	@make -C libft fclean
	@rm -rf $(NAME)
	@echo "$(RED)[minishell] : $(DEF)Full Cleaning       $(GRN)[OK]$(DEF)"

re: fclean all