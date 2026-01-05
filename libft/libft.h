/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thantoni <thantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:13:16 by thantoni          #+#    #+#             */
/*   Updated: 2026/01/03 17:02:35 by thantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define GNL_WIPE -4242
# define ERROR -1
# define TRUE 1
# define FALSE 0

typedef struct s_list
{
	void			*value;
	struct s_list	*next;
}	t_list;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
size_t			ft_strlen(const char *s);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strnstr(const char *haystack, \
	const char *needle, size_t len);
int				ft_atoi(const char *nptr);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
	void (*del)(void *));

char			*get_next_line(int fd);
int				ft_printf(char const *format, ...);

char			*ft_arraytostr(char **array);
void			ft_freesplit(char **split);
char			*ft_strjoin3(char const *s1, char const *s2, char const *s3);
void			*ft_first(void **array, void *ref, \
	int (f)(const void *, const void *));
int				ft_contains(const char *str, const char *ref);
int				ft_contains_v(const void *ptr, const void *cmp);
int				ft_contains_at(char *str, char *cmp, size_t at_index);
int				ft_startwith(char *str, char *cmp);
char			*ft_strdecapsulate(char *str, char mark);
char			cfirst(char *str);
char			clast(char *str);
char			is_cfirst(char *str, char cmp);
char			is_clast(char *str, char cmp);
int				ft_free(void **ptr);
int				ft_clamp(int val, int min, int max);
double			ft_clampf(double val, double min, double max);
char			ter_c(int con, char val_true, char val_false);
int				ter_i(int con, int val_true, int val_false);
long unsigned	ter_lu(int con, \
	long unsigned val_true, long unsigned val_false);
void			*ter_p(int con, void *val_true, void *val_false);
char			*ter_s(int con, char *val_true, char *val_false);
double			ter_f(int con, double val_true, double val_false);
void			invoke_f_list(t_list *f_list, void *value);

double			powx(double value, int pow);
double			pow2(double value);
double			pow3(double value);
double			sqrt(double value);
double			lerp(double origin, double target, double progress);
double			abs_f(double value);

t_list			*t_list__new(void *value);
void			t_list__add0(t_list **lst, t_list *new);
void			t_list__add1(t_list **lst, void *value);
t_list			*t_list__extract(t_list **lst, void *ptr);
char			t_list__c(t_list *list);
char			*t_list__s(t_list *list);

#endif