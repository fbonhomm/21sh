# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/30 00:13:50 by fbonhomm          #+#    #+#              #
#    Updated: 2016/06/08 15:30:50 by fbonhomm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

CC = gcc

LIB = -L libft/ -lft -ltermcap

FLAG = -Wall -Wextra -Werror

INC_PATH = ./inc/ \
			./libft/

SRC_PATH = ./src/

SRC_NAME = ft_search_git.c \
		end.c \
		execve_binary.c \
		ft_set_null.c \
		search_separ.c \
		print.c \
		env_to_stc.c \
		signal_stc.c \
		signal_lst.c \
		tilde.c \
		main.c \
		init.c \
		separator.c \
		ft_not_pipe.c \
		no_env.c \
		ft_split_quote.c \
		\
		builtins/build_unsetenv.c \
		builtins/build_cd.c \
		builtins/build_env.c \
		builtins/build_setenv.c \
		builtins/check_build.c \
		\
		pipe/ft_pipe.c \
		pipe/split_pipe.c \
		pipe/search_pipe.c \
		\
		redirection/ft_redir.c \
		redirection/split_redir.c \
		redirection/search_redir.c \
		redirection/redir_out.c \
		redirection/redir_in.c \
		redirection/heredoc.c \
		redirection/fusion_fd.c \
		redirection/ft_redir_pipe.c \
		redirection/other_split_redir.c \
		\
		termcaps/loop_primary.c \
		termcaps/term_control.c \
		termcaps/print_line.c \
		termcaps/open_history.c \
		termcaps/count_history.c \
		termcaps/next_word.c \
		termcaps/back_word.c \
		termcaps/up_history.c \
		termcaps/down_history.c \
		termcaps/del.c \
		termcaps/get_cursor.c \
		termcaps/reset_cursor.c \
		termcaps/start_and_end.c \
		termcaps/underline.c \
		termcaps/up_and_down.c \
		termcaps/paste.c \
		termcaps/init_standard.c \
		termcaps/init_termios.c \
		termcaps/insert.c \
		termcaps/parenthese.c \
		termcaps/search_history.c \
		termcaps/autocompletion.c \
		termcaps/switch_term.c \
		termcaps/pwd_history.c \
		termcaps/create_line.c \
		termcaps/conform.c

OBJ_PATH = ./obj/

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_FOLDER = ./obj/ \
			./obj/builtins/ \
			./obj/pipe/ \
			./obj/redirection/ \
			./obj/termcaps/

OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@$(CC) $(FLAG) $(OBJ) $(INC) $(LIB) -o $(NAME)
	@echo "Create: $(NAME)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_FOLDER)
	@$(CC) $(FLAG) $(INC) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@/bin/rm -rf $(OBJ_FOLDER)

fclean: clean
	@make fclean -C ./libft/
	@/bin/rm -f history
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
