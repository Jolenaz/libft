/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 14:53:56 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 15:32:35 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width_s(t_stu *stu, char *str)
{
	int i;

	i = stu->width - ft_strlen(str);
	if (stu->width && ((stu->flag & MOINSFLAG) == 0))
	{
		while (i)
		{
			if (stu->flag & ZEROFLAG)
				ft_putchar('0');
			else
				ft_putchar(' ');
			i--;
		}
		ft_putstr(str);
	}
	else if (stu->flag & MOINSFLAG)
	{
		ft_putstr(str);
		while (i)
		{
			ft_putchar(' ');
			i--;
		}
	}
}

void		ft_printf_s(t_stu *stu)
{
	char *str;

	if (stu->mod == l)
	{
		ft_printf_grs(stu);
		return ;
	}
	str = ft_strdup(va_arg(stu->ap, char *));
	if (str == NULL && stu->prcs == -1)
	{
		ft_putstr("(null)");
		return ;
	}
	else if (str == NULL)
		str = ft_strdup("\0");
	if ((size_t)stu->prcs <= ft_strlen(str))
	{
		str[stu->prcs] = 0;
	}
	if ((size_t)stu->width >= ft_strlen(str))
		ft_width_s(stu, str);
	else
		ft_putstr(str);
	free(str);
}
