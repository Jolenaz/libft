/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 17:00:08 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 13:23:36 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width(t_stu *stu)
{
	int		i;

	i = stu->width - 1;
	while (i)
	{
		if (stu->flag & ZEROFLAG && ((stu->flag & MOINSFLAG) == 0))
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
	}
}

void		ft_printf_c(t_stu *stu)
{
	if (stu->mod == l)
	{
		ft_printf_grc(stu);
		return ;
	}
	if (stu->let == -2000000000)
		(stu->let = va_arg(stu->ap, int));
	if ((size_t)stu->width)
	{
		if (stu->width && ((stu->flag & MOINSFLAG) == 0))
		{
			ft_width(stu);
			ft_putchar(stu->let);
		}
		else if (stu->flag & MOINSFLAG)
		{
			ft_putchar(stu->let);
			ft_width(stu);
		}
	}
	else
		ft_putchar(stu->let);
	stu->let = -2000000000;
}
