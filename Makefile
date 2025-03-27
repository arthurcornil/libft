# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acornil <acornil@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 01:37:04 by acornil           #+#    #+#              #
#    Updated: 2022/02/07 01:37:09 by acornil          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc 

CLFAGS=-Wall -Wextra -Werror

RM=rm -f

SRCS=ft_atoi.c\
	 ft_bzero.c\
	 ft_calloc.c\
	 ft_isalnum.c\
	 ft_isalpha.c\
	 ft_isascii.c\
	 ft_isdigit.c\
	 ft_isprint.c\
	 ft_memchr.c\
	 ft_memcmp.c\
	 ft_memcpy.c\
	 ft_memset.c\
	 ft_memmove.c\
	 ft_split.c\
	 ft_strchr.c\
	 ft_strdup.c\
	 ft_strlcat.c\
	 ft_strlcpy.c\
	 ft_strlen.c\
	 ft_strncmp.c\
	 ft_strnstr.c\
	 ft_strchr.c\
	 ft_strtrim.c\
	 ft_strrchr.c\
	 ft_substr.c\
	 ft_tolower.c\
	 ft_toupper.c\
	 ft_putchar_fd.c\
	 ft_putstr_fd.c\
	 ft_putendl_fd.c\
	 ft_putnbr_fd.c\
	 ft_strjoin.c\
	 ft_itoa.c\
	 ft_strmapi.c\
	 ft_strtrim.c\
	 ft_striteri.c

OBJS=${SRCS:.c=.o}

NAME=libft.a

BONUS= ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.o\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c

B_OBJS= ${BONUS:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} $?

bonus: ${B_OBJS} ${OBJS}
	ar rcs ${NAME} $?

clean:
	${RM} ${OBJS} ${B_OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: fclean clean re bonus
