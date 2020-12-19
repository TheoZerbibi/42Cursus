# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/19 12:13:48 by thzeribi          #+#    #+#              #
#    Updated: 2020/12/19 12:18:49 by thzeribi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

NAME					=	Cub3D
PROJECT_NAME	=	cub3d

SOURCES_FOLDER	=	./srcs/
INCLUDES_FOLDER	=	./includes/
OBJECTS_FOLDER	=	./objs/

SOURCES = \
	test.c \

LIBFT = ./libft/

OBJECTS		=		$(SOURCES:.c=.o)
OBJECTS		:=	$(subst /,__,$(OBJECTS))
OBJECTS		:=	$(addprefix $(OBJECTS_FOLDER),$(OBJECTS))
SOURCES		:=	$(addprefix $(SOURCES_FOLDER),$(SOURCES))

FSANITIZE	=	-g3 -fsanitize=address
#FLAGS		=	$(FSANITIZE)
#FLAGS		=	-Wall -Wextra -Werror $(FSANITIZE)
FLAGS			=	-Wall -Wextra -Werror
CC				=	clang

NO_COLOR 			=			\033[38;5;15m
OK_COLOR			=			\033[38;5;2m
ERROR_COLOR		=		\033[38;5;1m
WARN_COLOR		=		\033[38;5;3m
SILENT_COLOR	=	\033[38;5;245m
INFO_COLOR		=		\033[38;5;140m

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	@make -C $(LIBFT)
	@cp $(LIBFT)libft.a .
	@printf "$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed all objects$(NO_COLOR).\n"
	@printf "\n$(NO_COLOR)-------- $(INFO_COLOR) Start Compilation for Cub3D $(NO_COLOR)--------\n"
	@$(CC) $(FLAGS) -I$(INCLUDES_FOLDER) -o $(NAME) $(OBJECTS) ./libft.a
	@printf "%-50s \r"
	@printf "$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

force: $(OBJECTS)
	@printf "$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	@$(CC) $(FLAGS) -I$(INCLUDES_FOLDER) -o $(NAME) $(OBJECTS) ./libft.a
	@printf "%-50s \r"
	@printf "$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

$(OBJECTS_FOLDER)%.o: $(SOURCES_FOLDER)%.c
	@mkdir -p $(OBJECTS_FOLDER)
	#@mkdir -p $(OBJECTS_FOLDER)/flags
	#@mkdir -p $(OBJECTS_FOLDER)/utils
	@$(CC) $(FLAGS) -I$(INCLUDES_FOLDER) -c $< -o $@
	@printf "%-50s \r"
	@printf "$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled.$(OK_COLOR)✓$(NO_COLOR)\n"
	@printf "$(NO_COLOR)Creating $(INFO_COLOR)%-30s $(OK_COLOR)✓$(NO_COLOR)\r" "$@"

clean:
	@make -C libft clean
	@rm -f $(OBJECTS)
	@rm -f libft.a

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed $(INFO_COLOR)$(NAME)$(NO_COLOR).\n"
	
norm:
	norminette ./libft/{**/*.c,*.h}
	@echo
	norminette ./{$(INCLUDES_FOLDER),$(SOURCES_FOLDER)}

doclean: all clean

re: fclean all

.PHONY: all re clean fclean master force doclean norm
