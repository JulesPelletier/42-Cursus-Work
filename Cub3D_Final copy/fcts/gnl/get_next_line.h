/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:54:42 by juliodelave       #+#    #+#             */
/*   Updated: 2022/01/02 22:29:21 by julpelle         ###   ########.fr       */
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
# include "../libft/libft.h"

# define BUFFER_SIZE 32

int				ft_s_is(char *s, char c);
char			*ft_free(char *s);
void			ft_read_line(char **keep, char *buf, int *value, int fd);

int				get_next_line(int fd, char **line);

#endif
