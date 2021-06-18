/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_printf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julpelle <julpelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 10:34:28 by julpelle          #+#    #+#             */
/*   Updated: 2020/02/20 17:22:24 by julpelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_PRINTF_H
# define LIB_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int			flag;
	int			dash;
	int			zero;
	int			dot;
	int			star;
	int			width;
	int			precision;
	int			len;
	int			ret;
}				t_flags;

void			ft_putnbr_base(int nbr, char *base);
void			ft_putnbr_unsigned(long long int nb);
int				ft_is_flag(const char *str, int pos);
int				ft_is_converter(const char *str, int pos);
void			ft_init_flags(t_flags *flags);
int				search_flags(va_list va, const char *str, int pos
				, t_flags *flags);
void			flags_c(char c, t_flags *flags);
void			ft_dot_cx(unsigned long int nbr, t_flags *flags, char *base
				, int len);
void			flags_cx(unsigned long int nbr, t_flags *flags, char *base
				, int len);
unsigned int	unsigned_func(int n);
int				itoa_func(int nbr);
void			ft_dot(int nbr, t_flags *flags);
void			flags_id(int nbr, t_flags *flags);
void			ft_dot_p(int nbr, t_flags *flags, char *base);
void			flags_p(unsigned long int nbr, t_flags *flags, char *base);
void			flags_percent(t_flags *flags);
void			ft_dot_s(char *str, t_flags *flags);
void			flags_s(char *str, t_flags *flags);
char			*null_func(char *str);
int				itoa_func_u(unsigned int nbr);
void			ft_dot_u(unsigned int nbr, t_flags *flags);
void			flags_u(unsigned int nbr, t_flags *flags);
void			ft_dot_x(unsigned long int nbr, t_flags *flags, char *base
				, int len);
void			flags_x(unsigned long int nbr, t_flags *flags, char *base
				, int len);
unsigned int	unsigned_func_c(int n);
void			ft_putchar(char c, t_flags *flags);
int				ft_strlen_basehexa(unsigned long int n, char *base
				, t_flags *flags
				, int len);
void			ft_putnbr_basehexa(unsigned long int n, char *base
				, t_flags *flags);
void			ft_putnbr(int n, t_flags *flags);
void			ft_putstr(char *str, t_flags *flags);
void			ft_putunbr(unsigned int n, t_flags *flags);
int				ft_digitflags(const char *str, int pos, t_flags *flags);
int				ft_dispatch_conversion(const char *str, int pos,
				va_list params, t_flags *flags);
int				ft_display_c(int c, int pos, t_flags *flags);
int				ft_cx(int n, int pos, t_flags *flags);
int				ft_display_id(int nbr, int pos, t_flags *flags);
int				ft_p(unsigned long int n, int pos, t_flags *flags);
int				ft_display_perc(int pos, t_flags *flags);
int				ft_display_s(char *str, int pos, t_flags *flags);
int				ft_display_u(int nbr, int pos, t_flags *flags);
int				ft_x(int n, int pos, t_flags *flags);

int				ft_dashzero(const char *str, int pos, t_flags *flags, int nbr);
int				ft_precision(const char *str, int pos, t_flags *flags);
int				ft_width(const char *str, int pos, t_flags *flags);
int				ft_star(va_list va, const char *str, int pos, t_flags *flags);

#endif
