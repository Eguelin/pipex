# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:15:24 by eguelin           #+#    #+#              #
#    Updated: 2023/04/12 15:42:45 by eguelin          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Standard
OUT_DIR	= build/
SRC_DIR	= src/
INC_DIR	= include/
NAME	= mylib.a
CC		= cc
CFLAGS	= -Wall -Werror -Wextra -I $(INC_DIR)
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
GET_DIR = get/
GET_FILES = get_next_line.c
ALL_FILES = $(addprefix $(GET_DIR), $(GET_FILES))

MEM_DIR = mem/
MEM_FILES = ft_memset.c
ALL_FILES += $(addprefix $(MEM_DIR), $(MEM_FILES))

OTHER_DIR = other/
OTHER_FILES = ft_free_split.c ft_split.c
ALL_FILES += $(addprefix $(OTHER_DIR), $(OTHER_FILES))

PRINT_DIR = print/
PRINT_FILES = ft_print_address.c ft_print_all.c ft_print_base.c ft_print_char.c ft_printf.c ft_print_nbr.c ft_print_str.c
ALL_FILES += $(addprefix $(PRINT_DIR), $(PRINT_FILES))

PUT_DIR = put/
PUT_FILES = ft_putstr_fd.c
ALL_FILES += $(addprefix $(PUT_DIR), $(PUT_FILES))

STR_DIR = str/
STR_FILES = ft_strchr.c ft_strjoin.c ft_strjoin_three.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c
ALL_FILES += $(addprefix $(STR_DIR), $(STR_FILES))

INC_FILES	= mylib.h

OBJS		= $(addprefix $(OUT_DIR), $(ALL_FILES:.c=.o))
HEADERS		= $(addprefix $(INC_DIR), $(INC_FILES))

#Rules
all: $(NAME)

$(NAME): $(OUT_DIR) $(OBJS)
	$(ARC) $(NAME) $(OBJS)
	@echo $(COMP_MSG)
	@norminette | awk '$$NF!="OK!" {print "$(RED)" $$0 "$(WHITE)"}'

$(OUT_DIR)%.o : $(SRC_DIR)%.c $(HEADERS) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OUT_DIR)
	@echo $(CLEAN_MSG)

fclean: clean
	$(RM) $(NAME)
	@echo $(FULL_CLEAN_MSG)

re: fclean all

$(OUT_DIR):
	mkdir -p $(shell find $(SRC_DIR) -type d | awk -F "$(SRC_DIR)" '$$NF!="$(SRC_DIR)" {print "$(OUT_DIR)"$$(NF)}')

.PHONY: all clean fclean re
.SILENT:
