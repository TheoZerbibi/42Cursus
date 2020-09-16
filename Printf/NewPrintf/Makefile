# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 13:36:23 by thzeribi          #+#    #+#              #
#    Updated: 2020/09/16 03:44:37 by thzeribi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

NAME = libftprintf.a
PROJECT_NAME =	ft_printf \


SOURCES_FOLDER = ./srcs/
INCLUDES_FOLDER =	./includes/
OBJECTS_FOLDER = ./objs/

SRCS	:=	ft_printf.c	\
				elems.c				\
				ft_parsing.c	\
				\
				flags/do_s.c	\
				\
				utils/display.c

OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJECTS_FOLDER),$(OBJS))
SOURCES := $(addprefix $(SOURCES_FOLDER),$(SRCS))


FSANITIZE = -fsanitize=address
#FLAGS = -Wall -Wextra -Werror $(FSANITIZE)
FLAGS = -Wall -Wextra -Werror
GCC = clang
RM = rm -f

NO_COLOR 	=	\033[38;5;15m
OK_COLOR 	=	\033[38;5;2m
ERROR_COLOR =	\033[38;5;1m
WARN_COLOR 	=	\033[38;5;3m
SILENT_COLOR =	\033[38;5;245m
INFO_COLOR 	=	\033[38;5;140m

all: $(NAME)

$(NAME): $(OBJS)
	@printf "$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	@make -C libft
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed all objects$(NO_COLOR).\n"

$(OBJECTS_FOLDER)%.o: $(SOURCES_FOLDER)%.c
	@mkdir -p $(OBJECTS_FOLDER)
	@mkdir -p $(OBJECTS_FOLDER)/flags
	@mkdir -p $(OBJECTS_FOLDER)/utils
	@$(CC) $(FLAGS) -I$(INCLUDES_FOLDER) -c $< -o $@
	@printf "$(NO_COLOR)Creating $(INFO_COLOR)%-30s $(OK_COLOR)✓$(NO_COLOR)\r" "$@"

norm:
	norminette ./libft/*.c ; norminette ./libft/**/*.c
	@echo
	norminette ./$(INCLUDES_FOLDER)
	@echo
	norminette ./$(SOURCES_FOLDER)

clean:
	@make -C libft clean
	@rm -f $(OBJS)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed $(INFO_COLOR)$(NAME)$(NO_COLOR).\n"

doclean: all clean

re: fclean all

.PHONY: all re norm clean fclean libft m



# SRC_DIR  := ./srcs
# INC_DIR  := ./includes
# OBJ_DIR  := ./objs

# SRC	:=	ft_printf.c	\
# 				elems.c				\
# 				ft_parsing.c	\
# 				\
# 				flags/do_s.c

# OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

# # compiler
# CC		:= gcc
# CFLAGS	:= -Wall -Wextra -Werror
# CFLAGS	+= -O3 -march=native -pipe

# NAME	:= $(PRINTF_NAME)

# # rules
# all: $(NAME)

# $(OBJ_DIR):
# 	mkdir -p $(OBJ_DIR)
# 	mkdir -p $(OBJ_DIR)/flags

# $(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
# 	$(CC) $(CFLAGS) $(LIB_INC) -o $@ -c $<

# $(NAME): $(OBJ_DIR) $(OBJ)
# 	ar rc $(PRINTF_NAME) $(OBJ)
# 	ranlib $(PRINTF_NAME)

# test:
# 	@$(MAKE) -C $(TEST_DIR) --no-print-directory

# clean:
# 	rm -rf $(OBJ_DIR)

# fclean: clean
# 	rm -f $(PRINTF_NAME)

# re:
# 	@$(MAKE) fclean --no-print-directory
# 	@$(MAKE) all --no-print-directory

# .PHONY: all clean fclean re relibs test