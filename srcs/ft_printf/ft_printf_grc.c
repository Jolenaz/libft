/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_grc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 14:37:50 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 13:51:11 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width_grc(t_stu *stu, char c[4])
{
	int i;

	i = stu->width - ft_strlen(c);
	if (*c == 0)
		i--;
	while (i)
	{
		if (stu->flag & ZEROFLAG && ((stu->flag & MOINSFLAG) == 0))
			ft_putchar('0');
		else
			ft_putchar(' ');
		i--;
	}
}

static void	ft_put_grc(char c[4])
{
	if (*c)
		ft_putstr(c);
	else
		ft_putchar(0);
}

static void	ft_grc(t_stu *stu, char c[4])
{
	if ((size_t)stu->width >= ft_strlen(c) && stu->width)
	{
		if (stu->width && ((stu->flag & MOINSFLAG) == 0))
		{
			ft_width_grc(stu, c);
			ft_put_grc(c);
		}
		else if (stu->flag & MOINSFLAG)
		{
			ft_put_grc(c);
			ft_width_grc(stu, c);
		}
	}
	else
		ft_put_grc(c);
}

static void	ft_fill_wc(wchar_t wc, char c[4])
{
	if (wc <= 127)
		c[0] = (char)wc;
	else if (wc <= 2047)
	{
		c[0] = 192 | (wc >> 6);
		c[1] = 128 | (wc & 63);
	}
	else if (wc <= 65535)
	{
		c[0] = 224 | (wc >> 12);
		c[1] = 128 | ((wc >> 6) & 63);
		c[2] = 128 | (wc & 63);
	}
	else
	{
		c[0] = 240 | (wc >> 18);
		c[1] = 128 | ((wc >> 12) & 63);
		c[2] = 128 | ((wc >> 6) & 63);
		c[3] = 128 | (wc & 63);
	}
}

void		ft_printf_grc(t_stu *stu)
{
	wchar_t	wc;
	char	c[4];

	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	c[3] = 0;
	wc = va_arg(stu->ap, int);
	ft_fill_wc(wc, c);
	ft_grc(stu, c);
}
