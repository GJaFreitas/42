/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjacome- <gjacome-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 12:38:47 by gjacome-          #+#    #+#             */
/*   Updated: 2025/02/28 14:55:04 by bag              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// Printf

# define HEX_LOW "0123456789abcdef"
# define HEX_UP "0123456789ABCDEF"
# define BASE_10 "0123456789"
# define POSSIBLE_FLAGS "cspdiuxX%"

int		ft_printf(char *input, ...);
int		ft_nexus(char input, va_list args);
int		ft_putnbr_base(unsigned int nbr, char *base, int total);
int		ft_printchar(char c);
int		ft_printstring(char *str);
int		ft_printint(int n);
int		ft_printuint(unsigned int n);
int		ft_printhexbig(unsigned int n);
int		ft_printhexsmall(unsigned int n);
int		ft_printptr(void *ptr);

// Get Next Line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048
# endif

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *str, char *buffer);
int		ft_strlen_gnl(char *s, int flag);

// Strings

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(long int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);

// Checks

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

// Files

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *buf, int fd);
void	ft_putstr_fd(char *buf, int fd);
void	ft_putnbr_fd(int n, int fd);

// Memory

void	*ft_memset(void	*s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_malloc(size_t __size);

// Lists

t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstadd_back(t_list **head, t_list *node);
void	ft_lstadd_front(t_list **head, t_list *node);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));


#endif
