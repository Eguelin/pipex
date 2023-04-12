/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:54:43 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/12 16:20:32 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_H
# define MYLIB_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFFER_SIZE 16

////////// [ get ] //////////

char	*get_next_line(int fd);

////////// [ mem ] //////////

void	*ft_memset(void *b, int c, size_t len);

////////// [ other ] //////////

void	ft_free_split(char **tab);
char	**ft_split(char const *s, char c);

////////// [ print ] //////////

int		ft_print_nbr(int n);
int		ft_print_char(char c);
int		ft_print_str(const char *s);
int		ft_print_all(char c, va_list arg);
int		ft_print_address(unsigned long un);
int		ft_printf(const char *format, ...);
int		ft_print_base(unsigned long un, unsigned long size_set, char *set);

////////// [ put ] //////////

void	ft_putstr_fd(char *s, int fd);

////////// [ str ] //////////

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_three(char const *s1, char const *s2, char const *s3);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

#endif
