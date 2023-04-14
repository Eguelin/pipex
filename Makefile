# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:20:28 by eguelin           #+#    #+#              #
#    Updated: 2023/04/14 15:58:16 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Standard
OUT_DIR	= build/
SRC_DIR	= src/
INC_DIR	= include/
LIB_DIR	= lib/
NAME	= pipex
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I $(INC_DIR) #-g3 -fsanitize=address
RM		= rm -rf
ARC		= ar rcs

#Colors
BLACK	= \033[0;30m
RED		= \033[0;31m
GREEN	= \033[0;32m
YELLOW	= \033[0;33m
BLUE	= \033[0;34m
PURPLE	= \033[0;35m
CYAN	= \033[0;36m
WHITE	= \033[0;37m

#Sentence
COMP_MSG		= "$(GREEN)Compilation $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
COMP_BNS_MSG	= "$(GREEN)Compilation of bonus $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"

#Sources
ALL_FILES	= main.c ft_path.c ft_file.c ft_pipex.c ft_tools.c

MYLIB_DIR	= mylib/
MYLIB_FILES	= mylib.a
LIB_FILES	= $(addprefix $(MYLIB_DIR), $(MYLIB_FILES))

INC_FILES	= pipex.h

OBJS		= $(addprefix $(OUT_DIR), $(ALL_FILES:.c=.o))
HEADERS		= $(addprefix $(INC_DIR), $(INC_FILES))
LIB			= $(addprefix $(LIB_DIR), $(LIB_FILES))

#Sources bonus
BNS_DIR	= bonus/
BNS_FILES	= main_bonus.c ft_file_bonus.c ft_path_bonus.c ft_pipex_bonus.c ft_tools_bonus.c
ALL_BNS_FILES	= $(addprefix $(BNS_DIR), $(BNS_FILES))

BNS_INC_FILES	= pipex_bonus.h

BNS_OBJS	= $(addprefix $(OUT_DIR), $(ALL_BNS_FILES:.c=.o))
BNS_HEADERS	= $(addprefix $(INC_DIR), $(BNS_INC_FILES))

#Rules
all: $(NAME)

$(NAME): $(OUT_DIR) $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo $(COMP_MSG)
	@norminette | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c Makefile $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OUT_DIR) $(BNS_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(BNS_OBJS) $(LIB) -o $(NAME)
	@echo $(COMP_BNS_MSG)
	@norminette | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c Makefile $(BNS_HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C ./lib/mylib
	$(RM) $(OUT_DIR)
	@echo $(CLEAN_MSG)

fclean:
	$(MAKE) fclean -C ./lib/mylib
	$(RM) $(NAME) $(OUT_DIR)
	@echo $(CLEAN_MSG)
	@echo $(FULL_CLEAN_MSG)

force:

$(LIB): force
	$(MAKE) -C ./lib/mylib

$(OUT_DIR): force
	mkdir -p $(shell find $(SRC_DIR) -type d | awk -F "$(SRC_DIR)" '$$NF!="$(SRC_DIR)" {print "$(OUT_DIR)"$$(NF)}')

re: fclean all

.PHONY: all bonus clean fclean force re
#.SILENT:
