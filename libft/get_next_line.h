/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bajeanno <bajeanno@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:39:11 by bajeanno          #+#    #+#             */
/*   Updated: 2022/12/02 09:14:43 by bajeanno         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 50
# endif
# ifndef EOF
#  define EOF (-1)
# endif

void	*ft_memmove(void *dst, const void *src, size_t len);
char	*ft_strfusion(char const *buf, int *size, char *line, int buf_size);
char	*ft_realloc(char *str, int size);
int		ft_isset(char c, char const *set);
char	*get_next_line(int fd);

#endif