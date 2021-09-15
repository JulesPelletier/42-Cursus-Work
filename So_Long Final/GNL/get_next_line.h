/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Jules <Jules@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:54:42 by juliodelave       #+#    #+#             */
/*   Updated: 2021/09/15 23:38:55 by Jules            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include "../Libft/libft.h"

# define BUFFER_SIZE 10

size_t	ft_strlen_bis(const char *s);
int		check_charset(char c, char const *set);
void	ft_free(char *s);
char	*ft_strjoin_bis(char *s1, char *s2);
char	*ft_substr_bis(char *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif
