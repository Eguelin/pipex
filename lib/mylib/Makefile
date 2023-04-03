# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 15:15:24 by eguelin           #+#    #+#              #
#    Updated: 2023/03/28 12:04:17 by eguelin          ###   ########lyon.fr    #
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
FILES_GET = get_next_line.c
FILES_ALL = $(addprefix $(GET_DIR), $(FILES_GET))

IS_DIR = is/
FILES_IS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c
FILES_ALL += $(addprefix $(IS_DIR), $(FILES_IS))

LST_DIR = lst/
FILES_LST = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
FILES_ALL += $(addprefix $(LST_DIR), $(FILES_LST))

MEM_DIR = mem/
FILES_MEM = ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c
FILES_ALL += $(addprefix $(MEM_DIR), $(FILES_MEM))

OTHER_DIR = other/
FILES_OTHER = ft_atoi.c ft_bzero.c ft_calloc.c ft_free_split.c ft_itoa.c ft_split.c ft_tolower.c ft_toupper.c
FILES_ALL += $(addprefix $(OTHER_DIR), $(FILES_OTHER))

PRINT_DIR = print/
FILES_PRINT = ft_print_address.c ft_print_all.c ft_print_base.c ft_print_char.c ft_printf.c ft_print_nbr.c ft_print_str.c
FILES_ALL += $(addprefix $(PRINT_DIR), $(FILES_PRINT))

PUT_DIR = put/
FILES_PUT = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c
FILES_ALL += $(addprefix $(PUT_DIR), $(FILES_PUT))

STR_DIR = str/
FILES_STR = ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strjoin_three.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c
FILES_ALL += $(addprefix $(STR_DIR), $(FILES_STR))

INC_FILES	= mylib.h

OBJS		= $(addprefix $(OUT_DIR), $(FILES_ALL:.c=.o))
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
