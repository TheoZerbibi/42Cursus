# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 13:36:23 by thzeribi          #+#    #+#              #
#    Updated: 2019/11/15 05:22:14 by thzeribi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		 =		libft.a
PROJECT_NAME = Libft

SOURCES_FOLDER = ./
INCLUDES_FOLDER = ./
OBJECTS_FOLDER = ./

SRCS		=						\
				ft_atoi.c				\
				ft_bzero.c				\
				ft_calloc.c				\
				ft_isdigit.c			\
				ft_isalpha.c			\
				ft_isprint.c			\
				ft_putchar.c			\
				ft_putnbr.c				\
				ft_putstr.c				\
				ft_strdup.c				\
				ft_strncat.c			\
				ft_strlcat.c			\
				ft_strlen.c				\
				ft_nbrlen.c				\
				ft_strncmp.c			\
				ft_memset.c				\
				ft_strcpy.c				\
				ft_memcpy.c				\
				ft_memccpy.c			\
				ft_toupper.c			\
				ft_tolower.c			\
				ft_isalnum.c			\
				ft_isascii.c			\
				ft_strnstr.c			\
				ft_strlcpy.c			\
				ft_strchr.c				\
				ft_strrchr.c			\
				ft_memmove.c			\
				ft_strrev.c				\
				ft_memcmp.c				\
				ft_memchr.c				\
				ft_putchar_fd.c			\
				ft_putstr_fd.c			\
				ft_putnbr_fd.c			\
				ft_putendl_fd.c			\
				ft_strjoin.c			\
				ft_substr.c				\
				ft_strtrim.c			\
				ft_isspace.c			\
				ft_split.c				\
				ft_strmapi.c			\
				ft_itoa.c				\


BONUS_SRCS	=						\
				ft_lstnew_bonus.c		\
				ft_lstadd_front_bonus.c	\
				ft_lstsize_bonus.c		\
				ft_lstlast_bonus.c		\
				ft_lstadd_back_bonus.c	\
				ft_lstdelone_bonus.c	\
				ft_lstclear_bonus.c		\
				ft_lstiter_bonus.c		\
				ft_lstmap_bonus.c		\

OBJS		=		${SRCS:.c=.o}
BOBJS		=		${BONUS_SRCS:.c=.o}
FLAGS		=		-Wall -Wextra -Werror -Iincludes
CC			=		gcc
RM			=		rm -f

NO_COLOR 	=	\033[38;5;15m
OK_COLOR 	=	\033[38;5;2m
ERROR_COLOR =	\033[38;5;1m
WARN_COLOR 	=	\033[38;5;3m
SILENT_COLOR =	\033[38;5;245m
INFO_COLOR 	=	\033[38;5;140m

$(NAME): $(OBJS)
	@printf "$(NO_COLOR)All objects for $(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)where successfully created.\n"
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@printf "$(INFO_COLOR)$(NAME) $(NO_COLOR)successfully compiled. $(OK_COLOR)✓$(NO_COLOR)\n"

$(OBJECTS_FOLDER)%.o: $(SOURCES_FOLDER)%.c
	@$(CC) $(FLAGS) -Iincludes -c $< -o $@
	@printf "$(NO_COLOR)Creating $(INFO_COLOR)%-30s $(OK_COLOR)✓$(NO_COLOR)\r" "$@"

all: $(NAME)

bonus: $(NAME) $(BOBJS)
	@ar rc $(NAME) $(BOBJS)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(BOBJS)
	@printf "$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed all objects$(NO_COLOR).\n"


fclean: clean
	@$(RM) $(NAME)
	@printf "$(INFO_COLOR)$(PROJECT_NAME) $(NO_COLOR)Removed $(INFO_COLOR)$(NAME)$(NO_COLOR).\n"

re:	fclean all

.PHONY: all bonus clean fclean re
