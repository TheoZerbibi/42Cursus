/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thzeribi <thzeribi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:14:03 by thzeribi          #+#    #+#             */
/*   Updated: 2019/12/11 23:27:15 by thzeribi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef END_LINE
#  define END_LINE '\n'
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
int		get_line(int fd, char *buffer, char **files);
int		ft_multi_func(const char *str, int argc);
char	*ft_strnew_gnl(size_t size);
char	*ft_strcpy_gnl(char *dest, const char *src);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strchr_gnl(const char *s, int c);
void	ft_memdel_gnl(void **ap);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strdup_gnl(const char *src);

#endif
