/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:23:29 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/30 19:23:05 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
t_list			*ft_lstnew(void const *content, size_t content_size);
int				ft_atoi(const char *str);
void			ft_bzero(void *s, size_t n);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			*ft_memalloc(size_t size);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			ft_memdel(void **ap);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strchr(const char *s, int c);
void			ft_strclr(char *s);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_strdel(char **as);
char			*ft_strdup(const char *src);
int				ft_strequ(char const *s1, char const *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str1);
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strncat(char *dest, const char *src, size_t n);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strncpy(char *dst, const char *src, size_t len);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strnstr(const char *s1, const char *s2, size_t len);
char			*ft_strrchr(const char *s, int c);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strtrim(char const *s);
char			*ft_strcpy(char *dst, const char *src);
int				ft_tolower(int c);
int				ft_toupper(int c);
t_list			*ft_list_at(t_list *begin_list, unsigned int nbr);
t_list			*ft_list_push_params(int ac, char **av);
t_list			*ft_list_last(t_list *begin_list);
void			ft_add_to_end(t_list **begin_list, void *content);
void			ft_list_merge(t_list **begin_list1, t_list *begin_list2);

void			ft_print_chartab(char **tab);
void			ft_print_inttab(int *tab, int size);
int				ft_isin(char c, char *str);
int				ft_int_isin(int tofind, int *tab, int size);
void			ft_free_dblechar_tab(char **tab);
void			ft_free_dlbint_tab(int **tab, int size, int size2);
int				ft_strisin(char *tofind, char *str);
int				ft_strisin_tab(char *str, char **tab);
int				**ft_init_char_tab(int size, int size2);
int				*ft_init_int_tab(int size);
void			ft_capitalize(char *str);
int				ft_ismax(int i, int i2);
int				ft_ismin(int i, int i2);
void			*ft_realloc(void *content, size_t size);
#endif
