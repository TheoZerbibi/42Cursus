ifndef VERBOSE
MAKEFLAGS += --no-print-directory
endif

NAME = ft_printf
PROJECT_NAME = ft_printf

SOURCES_FOLDER = ./
INCLUDES_FOLDER = ./
OBJECTS_FOLDER = ./objects/

LIBS = NewPrintf
PRINTF = NewPrintf/libftprintf.a

SOURCES = \
	main.c \

OBJECTS = $(SOURCES:.c=.o)
OBJECTS := $(subst /,__,$(OBJECTS))
OBJECTS := $(addprefix $(OBJECTS_FOLDER),$(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER),$(SOURCES))

FSANITIZE = -g3 -fsanitize=address
FLAGS = $(FSANITIZE)
#FLAGS = -Wall -Wextra -Werror $(FSANITIZE)
#FLAGS = -Wall -Wextra -Werror
CC = clang

NO_COLOR =		\033[38;5;15m
OK_COLOR =		\033[38;5;2m
ERROR_COLOR =	\033[38;5;1m
WARN_COLOR =	\033[38;5;3m
SILENT_COLOR =	\033[38;5;245m
INFO_COLOR =	\033[38;5;140m

all: $(NAME)

$(LIBS):
	@printf "\n$(NO_COLOR)-------- $(INFO_COLOR)ft_printf $(NO_COLOR)--------\n"
	@make -C $(@)
	@printf "$(NO_COLOR)-----------------------\n\n"

$(NAME): $(LIBS) $(OBJECTS)
	@printf "\n$(NO_COLOR)-------- $(INFO_COLOR) Main Test $(NO_COLOR)--------\n"
	@$(CC) $(FLAGS) -I$(INCLUDES_FOLDER) -o $(NAME) $(OBJECTS) $(PRINTF)
	@printf "%-50s \r"
	@printf "$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

force: $(OBJECTS)
	@printf "$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	@$(CC) $(FLAGS) -I$(INCLUDES_FOLDER) -o $(NAME) $(OBJECTS) $(PRINTF)
	@printf "%-50s \r"
	@printf "$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

$(OBJECTS_FOLDER)%.o: $(SOURCES_FOLDER)%.c
	@mkdir -p $(OBJECTS_FOLDER)
	@$(CC) $(FLAGS) -I$(INCLUDES_FOLDER) -c $< -o $@
	@printf "$(NO_COLOR)Creating $(INFO_COLOR)%-30s $(OK_COLOR)✓$(NO_COLOR)\r" "$@"

clean:
	@make -C $(LIBS) clean
	@rm -f $(OBJECTS)
	@printf "$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed all objects$(NO_COLOR).\n"

fclean: clean
	@make -C $(LIBS) fclean
	@rm -f $(NAME)
	@rm -rf $(OBJECTS_FOLDER)
	@printf "$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed $(INFO_COLOR)$(NAME)$(NO_COLOR).\n"

doclean: all clean

re: fclean all

.PHONY: all re clean fclean NewPrintf force doclean
