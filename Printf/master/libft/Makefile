# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 13:36:23 by thzeribi          #+#    #+#              #
#    Updated: 2020/03/25 21:13:56 by thzeribi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PROJECT_NAME = LibFt

SOURCES_FOLDER = ./srcs/
INCLUDES_FOLDER = ./
OBJECTS_FOLDER = ./objs/

SOURCES = \
		ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_itoa.c \
		ft_lstadd_back_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstmap_bonus.c \
		ft_lstnew_bonus.c \
		ft_lstsize_bonus.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_nbrlen.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strcpy.c \
		ft_strndup.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strnew.c	\
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strcmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_putnbrmax_fd.c \


OBJECTS = $(SOURCES:.c=.o)
OBJECTS := $(subst /,__,$(OBJECTS))
OBJECTS := $(addprefix $(OBJECTS_FOLDER),$(OBJECTS))
SOURCES := $(addprefix $(SOURCES_FOLDER),$(SOURCES))

FLAGS = -Wall -Wextra -Werror
CC = clang

NO_COLOR =		\033[38;5;15m
OK_COLOR =		\033[38;5;2m
ERROR_COLOR =	\033[38;5;1m
WARN_COLOR =	\033[38;5;3m
SILENT_COLOR =	\033[38;5;245m
INFO_COLOR =	\033[38;5;140m

all: $(NAME)

$(NAME): $(OBJECTS)
	@printf "$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@printf "$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

$(OBJECTS_FOLDER)%.o: $(SOURCES_FOLDER)%.c
	@mkdir -p $(OBJECTS_FOLDER)
	@$(CC) $(FLAGS) -I$(INCLUDES_FOLDER) -c $< -o $@
	@printf "$(NO_COLOR)Creating $(INFO_COLOR)%-30s $(OK_COLOR)✓$(NO_COLOR)\r" "$@"

clean:
	@rm -f $(OBJECTS)
	@rm -rf $(OBJECTS_FOLDER)

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJECTS_FOLDER)

re: fclean all

.PHONY: all re clean fclean
