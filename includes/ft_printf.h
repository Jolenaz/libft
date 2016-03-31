/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 09:05:33 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/31 10:54:56 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# define NOFLAG 0
# define DIESFLAG 1
# define PLUSFLAG 2
# define MOINSFLAG 4
# define ESPFLAG 8
# define ZEROFLAG 16

typedef enum	e_mod
{
	none,
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_mod;

typedef struct	s_stu
{
	int		nb;
	int		isflag;
	char	flag;
	int		width;
	int		prcs;
	int		ismod;
	va_list	ap;
	t_mod	mod;
	char	conv;
	int		let;
}				t_stu;

int				ft_printf(const char *format, ...);
void			ft_printf_s(t_stu *stu);
void			ft_printf_p(t_stu *stu);
void			ft_printf_d(t_stu *stu);
void			ft_printf_x(t_stu *stu);
void			ft_printf_grx(t_stu *stu);
void			ft_printf_o(t_stu *stu);
void			ft_printf_u(t_stu *stu);
void			ft_printf_c(t_stu *stu);
void			ft_printf_grd(t_stu *stu);
void			ft_printf_gro(t_stu *stu);
void			ft_printf_gru(t_stu *stu);
void			ft_printf_grc(t_stu *stu);
void			ft_printf_grs(t_stu *stu);
void			ft_printf_flag(t_stu *stu, char *str, int neg);
void			ft_printf_parser1(char **str, t_stu *stu);
void			ft_printf_parser2(char **str, t_stu *stu);
int				ft_printf_parser3(char **str, t_stu *stu, int *i);

#endif
