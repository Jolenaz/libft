/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_grs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/25 17:16:56 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 16:10:00 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill_wc(int *i, char *c, int b)
{
	static int l = 0;

	if (*i <= 127)
		c[l++] = (char)(*i);
	else if (*i <= 2047)
	{
		c[l++] = 192 | (*i >> 6);
		c[l++] = 128 | (*i & 63);
	}
	else if (*i <= 65535)
	{
		c[l++] = 224 | (*i >> 12);
		c[l++] = 128 | ((*i >> 6) & 63);
		c[l++] = 128 | (*i & 63);
	}
	else
	{
		c[l++] = 240 | (*i >> 18);
		c[l++] = 128 | ((*i >> 12) & 63);
		c[l++] = 128 | ((*i >> 6) & 63);
		c[l++] = 128 | (*i & 63);
	}
	if (b == 0)
		l = 0;
}

static char	*ft_wstr(int *i)
{
	char	*c;

	c = ft_strnew(sizeof(i));
	while (*i)
	{
		ft_fill_wc(i, c, 1);
		i++;
	}
	ft_fill_wc(i, c, 0);
	return (c);
}

static int	ft_prcs_ws(char *str, int prcs)
{
	int i;

	i = 0;
	while (i < prcs)
	{
		if ((prcs - i) < 2 && ((str[i] & 192) == 192))
			break ;
		else if ((prcs - i) < 3 && ((str[i] & 224) == 224))
			break ;
		else if ((prcs - i) < 4 && ((str[i] & 240) == 240))
			break ;
		i++;
	}
	return (prcs - i);
}

static void	ft_width_grs(t_stu *stu, char *str)
{
	int		l;

	if (stu->width && ((stu->flag & MOINSFLAG) == 0))
	{
		l = stu->width - ft_strlen(str);
		while (l)
		{
			if (stu->flag & ZEROFLAG)
				ft_putchar('0');
			else
				ft_putchar(' ');
			l--;
		}
		ft_putstr(str);
	}
	else if (stu->flag & MOINSFLAG)
	{
		l = stu->width - ft_strlen(str);
		ft_putstr(str);
		while (l)
		{
			ft_putchar(' ');
			l--;
		}
	}
}

void		ft_printf_grs(t_stu *stu)
{
	int		*i;
	char	*str;
	int		m;

	i = va_arg(stu->ap, int*);
	m = 0;
	if (i == NULL && stu->prcs == -1)
	{
		ft_putstr("(null)");
		return ;
	}
	else if (i == NULL)
		str = ft_strdup("\0");
	str = ft_wstr(i);
	if (stu->prcs <= (int)ft_strlen(str) && stu->prcs != -1)
	{
		m = ft_prcs_ws(str, stu->prcs);
		str[stu->prcs - m] = 0;
	}
	if (stu->width >= (int)ft_strlen(str))
		ft_width_grs(stu, str);
	else
		ft_putstr(str);
	free(str);
}
