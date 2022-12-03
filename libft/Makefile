#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbasilio <jbasilio@student.42lisboa.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 21:02:40 by jbasilio          #+#    #+#              #
#    Updated: 2022/11/18 23:46:42 by jbasilio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_isalpha.c ft_isprint.c ft_memcpy.c ft_strchr.c ft_strlen.c ft_strrchr.c \
	ft_bzero.c ft_isascii.c ft_memchr.c ft_memmove.c ft_strlcat.c ft_strncmp.c ft_tolower.c \
	ft_isalnum.c ft_isdigit.c ft_memcmp.c ft_memset.c ft_strlcpy.c ft_strnstr.c ft_toupper.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c \
	ft_printf.c 


SRC_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	    ft_lstclear.c ft_lstiter.c ft_lstmap.c 

OBJ = ${SRC:.c=.o} 

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

COMPILE = cc $(CFLAGS) -c

LIB = ar -rcs $(NAME)

REMOVE = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(OBJ) 

bonus:
	@$(COMPILE) $(SRC_BONUS)
	@$(LIB) $(OBJ_BONUS)

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all

.PHONY: all clean fclean re
