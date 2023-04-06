# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 14:20:28 by eguelin           #+#    #+#              #
#    Updated: 2023/04/06 16:49:10 by eguelin          ###   ########lyon.fr    #
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
CLEAN_MSG		= "$(RED)Cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"
FULL_CLEAN_MSG	= "$(PURPLE)Full cleaning $(NAME) $(WHITE)done on $(YELLOW)$(shell date +'%Y-%m-%d %H:%M:%S')$(WHITE)"

#Sources
ALL_FILES = main.c
#..._DIR = ../
#ALL_FILES = ..
#ALL_FILES = $(addprefix $(..._DIR), $(..._FILES))

MYLIB_DIR = mylib/
MYLIB_FILES = mylib.a
LIB_FILES = $(addprefix $(MYLIB_DIR), $(MYLIB_FILES))

INC_FILES	= pipex.h

OBJS		= $(addprefix $(OUT_DIR), $(ALL_FILES:.c=.o))
HEADERS		= $(addprefix $(INC_DIR), $(INC_FILES))
LIB			= $(addprefix $(LIB_DIR), $(LIB_FILES))

#Rules
all: $(NAME)

$(NAME): $(OUT_DIR) $(OBJS) $(LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo $(COMP_MSG)
	@norminette | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c $(HEADERS) Makefile
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

re: fclean all

$(LIB): force
	$(MAKE) -C ./lib/mylib

$(OUT_DIR): force
	mkdir -p $(shell find $(SRC_DIR) -type d | awk -F "$(SRC_DIR)" '$$NF!="$(SRC_DIR)" {print "$(OUT_DIR)"$$(NF)}')

force:

.PHONY: all clean fclean re force
.SILENT:
