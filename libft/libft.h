/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbonhomm <fbonhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:46:16 by fbonhomm          #+#    #+#             */
/*   Updated: 2016/06/11 18:22:54 by fbonhomm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>
# include <ctype.h>
# include <errno.h>
# include <time.h>

# define SIZE 10000

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_env
{
	int				rd;
	int				j;
	int				i;
	int				ind;
	int				ret;
}					t_env;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strndup(const char *s1, size_t size);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **list, void (*del)(void*, size_t));
void				ft_lstdel(t_list **list, void (*del)(void *, size_t));
void				ft_lstadd(t_list **list, t_list *lst);
void				ft_lstiter(t_list *list, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem));
void				ft_lstaddend(t_list **list, t_list *lst);
int					ft_strlen_first_dim(char **str);
int					ft_strlen_second_dim(char **str);
void				ft_error();
int					get_next_line(int const fd, char **line);
void				ft_putstr_color(char *color, char *text_back, char *text,
						char *text_suite);
char				**ft_free_array(char **str);
void				ft_put_array(char **str, char *c);
char				**ft_strdup_array(char **str);
char				**ft_split(char const *s, char c, char d);
char				*ft_free(char *str);
char				*ft_realloc(char **str, size_t size);
int					ft_in_read_line(char **line, t_env *env, int fd,
						char *buff);
int					ft_search_true(char const *s, char *c, int i);
int					ft_search_false(char const *s, char *c, int i);
char				**ft_split_mult(int nb, char const *str, ...);
void				ft_print_str(int nb, ...);
void				ft_print_nbr(int nb, ...);
void				ft_print_err(char *str);
char				*ft_eof(char *str);
int					ft_strch_eof(char *str);
int					ft_sleep(long miliseconds);
int					ft_sort_str(char *s1, char *s2);
int					ft_sort_str_nocasse(char *s1, char *s2);
char				*ft_strjoin_mult(int nb, ...);
void				ft_print_str_endl(int nb, ...);
char				*ft_strepur(int nb, char *str, ...);
void				ft_perror(char *s);
char				*ft_strjoin_and_free(char **s1, char *s2);

#endif
