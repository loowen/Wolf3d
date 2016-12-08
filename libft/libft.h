/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meckhard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 11:20:43 by meckhard          #+#    #+#             */
/*   Updated: 2016/06/18 14:27:15 by meckhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10
# define LL_INT long long int
# define ULL_INT unsigned long long int

# include <stdarg.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include "libc.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}                   t_list;

typedef	struct		s_flags
{
    int		has_flags;
    int		plus;
    int		minus;
    int		zero;
    int		hash;
    int		space;
    int		prec;
    int		ip;
    int		padding;
    char	pad;
}					t_flags;

typedef struct		s_mods
{
    int	has_mod;
    int	ln;
    int	sht;
    int	u_sign;
    int	zee;
    int	jay;
}					t_mods;

int					get_next_line(const int fd, char **line);
char				**ft_strsplit(char const *s, char c);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
char				*ft_itoa(int n);
char				*ft_strjoin(char const *s1, char const *s2);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strnew(size_t size);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strtrim(const char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
void				ft_strdel(char **as);
void				ft_memdel(void **ap);
void				*ft_memalloc(size_t size);
void				ft_strclr(char *s);
int					ft_strnqu(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_putstr(const char *s);
void				ft_putstr_fd(const char *s, int fd);
int					ft_atoi(const char *src);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void				*ft_memchr(const void *s1, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *s1, const void *s2, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strdup(const char *s1);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void				*ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));

int					ft_printf(const char *format, ...);
int					is_pflag(char c);
int					is_pmodifier(char c);
int					is_psigned(char c);
int					is_pnumeric(char c);
int					ft_out(char type, char *out, t_flags fl);
char				*convert(long long num, int base, int hex_upper);
char				*convert_uns(ULL_INT num, int base, int hex_upper);
char				*ft_check(const char *str, t_mods md, va_list *args);
char				*ft_check_mod(const char *str, t_mods md, va_list *args);
char				*convert_uns_l(LL_INT num, int base, int hex_upper);
t_flags				init_flags(void);
t_mods				init_mods(void);
void				ft_putstr_w(char *str, int *w, int inc);

#endif
