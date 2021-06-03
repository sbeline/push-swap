/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbeline <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 17:04:58 by sbeline           #+#    #+#             */
/*   Updated: 2016/10/17 17:05:15 by sbeline          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <time.h>
# include <wchar.h>
# include <limits.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <stdio.h>
# include <termios.h>
# include <unistd.h>
# define BUF_SIZE 1496
# define FILES 50
# define REP 60
# define LINK 70

typedef	struct		s_fd
{
	int				fd;
	int				nl;
	size_t			pos_nl;
	int				ret;
	char			*buf;
	struct s_fd		*next;
}					t_fd;

char				*ft_chrstr(char *str, char *find);
int					is_dir(char *s);
char				*ft_strndup(char *s, int begin, int end);
char				*ft_strtrijoin(const char *s1, const char *s2,
									const char *s3);
int					get_next_line(int fd, char **line);
int					ft_lenghtunint(unsigned int nb);
int					ft_lenghtlong(long long ll);
int					ft_lenghtunlong(unsigned long long ll);
void				ft_printunlong(unsigned long long ll);
void				ft_printunint(unsigned int n);
void				ft_printlong(long long ll);
int					ft_lenghstrwchar(const wchar_t *wc);
int					ft_lenghtwchar(wchar_t wc);
void				ft_putwstr(wchar_t *s);
void				ft_putwstr_fd(wchar_t *s, int fd);
void				ft_putwchar(wchar_t wc);
void				ft_putwchar_fd(wchar_t wc, int fd);
size_t				ft_nbsize(int nb);
void				ft_putstr_rev(char *s, int size);
int					ft_strnb(void *var);
int					ft_strcmp_size(off_t s1, off_t s2, int reverse);
int					ft_strcmp_date(time_t t1, time_t t2, int reverse);
int					ft_strcmp_name(char *s1, char *s2);
char				*strconct(char *s1, char *s2, const char *obj);
char				*ft_strcatdup(const char *s1, const char *s2);
int					ft_findstr(char *s1, char *s2);
char				*ft_convert_s(char **s);
int					ft_lenght_array(char **str);
int					ft_getnbr(char *s);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_strcat(char *s1, const char *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_strchr(char *s, char c);
void				ft_strmove(char **s, int pos);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strcpy(char *s1, const char *s2);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
int					ft_unspace(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strdup(const char *s1);
char				*ft_strndup(char *s, int begin, int end);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size, const char *s);
char				*ft_stradd(char **s1, char **s2);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strnjoin(char *s1, char *s2, int begin, int end);
char				*ft_strtrim(char const *s);
int					ft_strsplit(char ***dst, char const *s, int *t);
int					ft_strisdigit(char *str);
int					get_next_line(int fd, char **line);
int					ft_nblen(int n);
void 				ft_printmuliplecar(int nb,char c);

typedef struct		s_llist
{
	int				content;
	size_t		content_size;
	int				smallest;
	int				lastest;
	struct s_llist	*next;
	struct s_llist	*prev;
}					t_llist;

typedef struct		s_dllist
{
	size_t					lenght;
	struct s_llist	*last_entry_smallest;
	struct s_llist	*head;
	struct s_llist	*tail;
}					t_dllist;

t_llist			*ft_lstnew(int content, size_t content_size);
void				ft_lstdel(t_llist **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_llist **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_dllist **alst, t_llist *n);
void				ft_lstiter(t_llist *lst, void (*f)(t_llist *elem));
void				ft_lsttri(t_llist **alst, int opt);
t_llist			*ft_lstmap(t_llist *lst, t_llist *(*f)(t_llist *elem));
t_llist			*ft_list_search(t_llist *e, int str);

#endif
