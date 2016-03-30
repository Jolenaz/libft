/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 17:31:06 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 17:38:29 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_prcs_width(char *c, t_stu *stu)
{
	if (*(c - 1) == '.')
		stu->prcs = ft_atoi(c);
	else
		stu->width = ft_atoi(c);
	while (*c >= '0' && *c <= '9')
	{
		c++;
	}
	return (--c);
}

static void	ft_fct(void (*ft_conv[127])(t_stu*))
{
	ft_conv['s'] = &ft_printf_s;
	ft_conv['i'] = &ft_printf_d;
	ft_conv['d'] = &ft_printf_d;
	ft_conv['p'] = &ft_printf_p;
	ft_conv['x'] = &ft_printf_x;
	ft_conv['X'] = &ft_printf_grx;
	ft_conv['o'] = &ft_printf_o;
	ft_conv['u'] = &ft_printf_u;
	ft_conv['c'] = &ft_printf_c;
	ft_conv['D'] = &ft_printf_grd;
	ft_conv['O'] = &ft_printf_gro;
	ft_conv['U'] = &ft_printf_gru;
	ft_conv['C'] = &ft_printf_grc;
	ft_conv['S'] = &ft_printf_grs;
}

void		ft_parser1(char **str, t_stu *stu)
{
	if (**str == 'h')
	{
		if (*(*str + 1) == 'h')
		{
			stu->mod = hh;
			(*str)++;
		}
		else
			stu->mod = h;
	}
	else if (**str == 'l')
	{
		if (*(*str + 1) == 'l')
		{
			stu->mod = ll;
			(*str)++;
		}
		else
			stu->mod = l;
	}
	else if (**str == 'j')
		stu->mod = j;
	else if (**str == 'z')
		stu->mod = z;
}

void		ft_parser2(char **str, t_stu *stu)
{
	if (**str == '.')
	{
		if ((*(*str + 1) < '1' || *(*str + 1) > '9') && *(*str + 1) != '*')
			stu->prcs = 0;
	}
	else if (**str >= '0' && **str <= '9')
		*str = ft_prcs_width(*str, stu);
	else if (**str == '*')
	{
		if (*(*str - 1) == '.')
			stu->prcs = va_arg(stu->ap, int);
		else
		{
			stu->width = va_arg(stu->ap, int);
			if (stu->width < 0)
			{
				stu->width *= -1;
				stu->flag = stu->flag | MOINSFLAG;
			}
		}
	}
}

int			ft_parser3(char **str, t_stu *stu, int *i)
{
	void	(*ft_conv[127])(t_stu*);

	ft_fct(ft_conv);
	if (ft_strchr("sSpdDioOuUxXcC", **str) && **str)
	{
		stu->conv = **str;
		(ft_conv[(int)**str])(stu);
		(*i)++;
		return (1);
	}
	else
	{
		if (**str)
		{
			stu->let = **str;
			ft_printf_c(stu);
			(*str)++;
		}
		return (0);
	}
}
