# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/20 18:13:56 by clouaint          #+#    #+#              #
#    Updated: 2024/08/12 12:16:04 by clouaint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

LIBC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_calloc.c \
ft_strlcpy.c ft_toupper.c ft_tolower.c ft_strnstr.c ft_strlcat.c \
ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_strdup.c

FSUPP = ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
ft_substr.c ft_strjoin.c ft_strmapi.c ft_striteri.c ft_itoa.c ft_split.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OTHERS = get_next_line.c ft_printf.c

SRCS = $(LIBC) $(FSUPP)

SRCSALL = $(SRCS) $(BONUS) $(OTHERS)

OBJS = $(SRCS:.c=.o)

OBJSALL = $(SRCSALL:.c=.o)

all : $(NAME)

$(NAME): $(OBJSALL)
	ar -rsc $(NAME) $(OBJSALL)

.c.o:
	@echo -n "$(basename $<) "
	@cc -I. -o $@ -c $< $(CFLAGS)

clean:
	rm -rf $(OBJSALL)

fclean: clean
	rm -rf $(NAME)

re: fclean all
