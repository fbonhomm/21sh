/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/16 14:02:47 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/08 17:54:19 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH21_H
# define SH21_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <signal.h>
# include <dirent.h>
# include <errno.h>
# include <term.h>
# include <sys/ioctl.h>
# include <fcntl.h>
# include <dirent.h>
# include "libft.h"

# define LEFT		buf[0] == 27 && buf[1] == 91 && buf[2] == 68 && buf[3] == 0
# define RIGHT		buf[0] == 27 && buf[1] == 91 && buf[2] == 67 && buf[3] == 0
# define UP			buf[0] == 27 && buf[1] == 91 && buf[2] == 65 && buf[3] == 0
# define DOWN		buf[0] == 27 && buf[1] == 91 && buf[2] == 66 && buf[3] == 0
# define TAB		buf[0] == 9 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define ENTER		buf[0] == 10 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define CTRLD		buf[0] == 4 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define CTRLL		buf[0] == 12 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define CTRLE		buf[0] == 5 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define CTRLW		buf[0] == 23 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define CTRLP		buf[0] == 16 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define CTRLU		buf[0] == 21 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define CTRLI		buf[0] == 9 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define CTRLR		buf[0] == 18 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define DEL		buf[0] == 127 && buf[1] == 0 && buf[2] == 0 && buf[3] == 0
# define HOME		buf[0] == 27 && buf[1] == 91 && buf[2] == 72 && buf[3] == 0
# define END		buf[0] == 27 && buf[1] == 91 && buf[2] == 70 && buf[3] == 0
# define CLEAR		"cl"
# define DEL_LINE	"dl"
# define MVRIGHT	"nd"
# define MVLEFT		"le"
# define MAX		512
# define MAX_PARENT	10000

typedef struct		s_stc
{
	char			**separator;
	char			**pipe;
	char			**redir;
	char			**env;
	char			**env_tmp;
	char			**path;
	char			**command;
	char			*str_path;
	char			*pwd;
	char			*old_pwd;
	char			*buf;
	char			*tmp;
	char			*home;
	char			*name;
	char			*path_git;
	int				ctrl_c;
	int				pip;
	int				red;
	int				pv;
	int				et;
	int				git;
	int				redir_in;
	int				redir_out;
	int				fd_err;
	int				fd_out;
	int				fd_in;
	int				out;
	int				in;
	int				err;
	int				index;
}					t_stc;

typedef struct		s_lst
{
	char			buffer[MAX];
	char			tmp_history[MAX];
	char			tmp_compl[MAX];
	char			path[MAX];
	char			clipboard[MAX];
	char			path_compl[MAX];
	char			*p;
	int				index_color;
	int				index;
	int				col;
	int				pos_x;
	int				pos_y;
	int				index_history;
	int				ind_hist_max;
}					t_lst;

struct termios		g_old_term;

/*
** builtins
*/
void				build_cd(t_stc *stc);
void				build_setenv(t_stc *stc, char *str);
void				build_unsetenv(t_stc *stc);
void				build_env(t_stc *stc);
int					err_env(int ret);
/*
** fonction qui redirige vers les buildtins
*/
int					ft_builtin(t_stc *stc);
int					ft_option_1(t_stc *stc);
int					ft_option_2(t_stc *stc);
int					ft_option_3(t_stc *stc);
int					ft_option_4(t_stc *stc);
int					ft_option_5(t_stc *stc);
/*
** initialise a null
*/
void				ft_set_null(t_stc *stc);
char				*change_pwd(t_stc *stc, char *str, int i);
/*
** fonction qui regroupe des fonction d'initialisation
*/
void				init(t_stc *stc, char **env);
void				read_comm_pipe(t_stc *stc);
/*
** fonction qui donne(nt) les valeurs du env pour la structure
*/
void				env_to_stc(t_stc *stc);
/*
** fonction d'affichage
*/
void				welcome();
void				prompt(t_stc *stc, t_lst *lst, int i);
void				no_env();
/*
** fonction qui gere le tilde
*/
void				tilde(t_stc *stc, char ***tabl);
/*
** fonction qui cherche les separateur (;, &&, ") et qui les separent
*/
int					search_separ(t_stc *stc);
void				separator(t_stc *stc);
char				**ft_split_quote(char const *s);
/*
** fonction qui execute avec execve
*/
void				execve_binary(t_stc *stc);
/*
** fonction pour les signaux
*/
void				get_signal();
t_stc				*signal_stc(t_stc *tmp);
t_lst				*signal_lst(t_lst *tmp);
/*
** fonction qui detecte les .git
*/
void				ft_search_git(t_stc *stc);
/*
** fonction qui retourne le nombre d'occurence du signe egal
*/
int					search_egal(char *str, int i);
/*
** fonction du pipe
*/
int					search_pipe(t_stc *stc, int i);
void				split_pipe(t_stc *stc, int i);
void				ft_pipe(t_stc *stc, t_lst *lst);
int					no_program(t_stc *stc);
/*
** fonction des redirections
*/
int					search_redir(t_stc *stc, int i);
void				split_redir(t_stc *stc, int i);
void				ft_redir(t_stc *stc, int i, int j, t_lst *lst);
void				redir_out(t_stc *stc, int *j);
void				redir_in(t_stc *stc, int *j);
void				have_redir(t_stc *stc);
int					open_redir(t_stc *stc);
int					ft_valid(t_stc *stc, int j);
void				close_fd(t_stc *stc);
int					heredoc(t_stc *stc, int *j, t_lst *lst);
int					more_tall(int out, int in, int err);
int					fusion_fd(char *str);
void				ft_redir_pipe(t_stc *stc, int i, t_lst *lst);
void				condition_loop(t_stc *stc, int *a, int *b);
void				ft_count_tab(t_stc *stc, int index);
/*
** fonction termcaps
*/
void				loop_primary(t_stc *stc, t_lst *lst);
int					term_control(t_stc *stc, t_lst *lst, char *buf);
int					ft_outc(int c);
void				get_cursor(char *command, t_lst *lst);
void				print_line(t_lst *lst, char *buf);
void				open_history(t_lst *lst);
void				count_history(t_lst *lst);
int					up_history(t_lst *lst);
int					down_history(t_lst *lst);
int					next_word(t_lst *lst);
int					del(t_lst *lst, char *buf);
int					back_word(t_lst *lst);
void				reset_cusor(t_lst *lst, int len);
int					start_and_end(t_lst *lst, char *buf);
int					underline(t_lst *lst, char *tmp);
int					up_and_down(t_lst *lst, char *buf);
int					paste(t_lst *lst);
void				create_line(t_lst *lst, char car);
void				init_termios(void);
void				init_standard(void);
void				insert(t_lst *lst, t_stc *stc, char *buf);
int					parenthese(t_lst *lst, t_stc *stc);
int					search_history(t_lst *lst);
int					autocompletion(t_lst *lst);
int					switch_term(t_lst *lst);
void				create_line(t_lst *lst, char car);
void				pwd_history(t_lst *lst);
int					conform(char *buf);
/*
** other
*/
void				ft_not_pipe(t_stc *stc, t_lst *lst);
void				ft_check(t_stc *stc, t_lst *lst);
void				end(t_stc *stc, int index);

#endif
