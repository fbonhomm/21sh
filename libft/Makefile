# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/01 17:46:33 by fbonhomm          #+#    #+#              #
#    Updated: 2016/06/08 15:30:27 by fbonhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADERS = ./

SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strndup.c \
	  ft_strrchr.c \
	  ft_strstr.c \
	  ft_strsplit.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_lstnew.c \
	  ft_lstdelone.c \
	  ft_lstdel.c \
	  ft_lstadd.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstaddend.c \
	  ft_strlen_first_dim.c \
	  ft_strlen_second_dim.c \
	  ft_error.c \
	  get_next_line.c \
	  ft_putstr_color.c \
	  ft_free_array.c \
	  ft_strdup_array.c \
	  ft_put_array.c \
	  ft_split.c \
	  ft_free.c \
	  ft_realloc.c \
	  ft_in_read_line.c \
	  ft_split_mult.c \
	  ft_split_mult_other.c \
	  ft_print_str.c \
	  ft_print_nbr.c \
	  ft_print_err.c \
	  ft_eof.c \
	  ft_strch_eof.c \
	  ft_sleep.c \
	  ft_sort_str.c \
	  ft_sort_str_nocasse.c \
	  ft_strjoin_mult.c \
	  ft_print_str_endl.c \
	  ft_strepur.c \
	  ft_perror.c \
	  ft_strjoin_and_free.c \

OBJET=$(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@gcc -c -Wall -Wextra -Werror $(SRC) -I$(HEADERS)
	@ar rc $(NAME) $(OBJET)
	@ranlib $(NAME)
	@make clean

clean:
	@/bin/rm -f $(OBJET)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
