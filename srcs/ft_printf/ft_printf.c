/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 09:14:41 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 17:33:38 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flag(char c, t_stu *stu)
{
	if (c == '#')
		stu->flag = stu->flag | DIESFLAG;
	else if (c == '+')
		stu->flag = stu->flag | PLUSFLAG;
	else if (c == '-')
		stu->flag = stu->flag | MOINSFLAG;
	else if (c == ' ')
		stu->flag = stu->flag | ESPFLAG;
	else if (c == '0')
		stu->flag = stu->flag | ZEROFLAG;
	if (stu->flag & PLUSFLAG)
		stu->flag = stu->flag & ~ESPFLAG;
}

static char	*ft_read(char *str, t_stu *stu, int *i)
{
	char	cont;

	cont = 1;
	while (cont)
	{
		if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
			ft_parser1(&str, stu);
		else if (*str == '#' || *str == '+' || *str == '-' ||
				*str == ' ' || (*str == '0' && *(str - 1) != '.'))
			ft_flag(*str, stu);
		else if (*str == '.' || (*str >= '0' && *str <= '9') || *str == '*')
			ft_parser2(&str, stu);
		else
		{
			if (ft_parser3(&str, stu, i) == 1)
				cont = 0;
			else
				return (str);
		}
		str++;
	}
	return (str);
}

static void	ft_read_format(const char *str, t_stu *stu)
{
	char	*c;
	int		i;

	i = 0;
	c = (char *)str;
	while (*c)
	{
		if (*c == '%')
			c = ft_read(c + 1, stu, &i);
		else
		{
			ft_putchar(*c);
			c++;
		}
	}
	stu->nb = i;
}

static void	ft_init_stu(t_stu *stu)
{
	stu->flag = 0;
	stu->mod = none;
	stu->conv = 0;
	stu->prcs = -1;
	stu->width = 0;
	stu->let = -2000000000;
}

int			ft_printf(const char *str, ...)
{
	int		res;
	t_stu	stu;

	ft_init_stu(&stu);
	va_start(stu.ap, str);
	ft_read_format(str, &stu);
	res = ft_singleton(-1);
	ft_singleton(0);
	va_end(stu.ap);
	return (res);
}
