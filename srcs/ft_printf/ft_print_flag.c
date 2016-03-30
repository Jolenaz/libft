/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:10:47 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 16:17:29 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_pref(t_stu *stu, int neg)
{
	if (neg)
		ft_putchar('-');
	else if (stu->flag & PLUSFLAG)
		ft_putchar('+');
	else if (stu->flag & ESPFLAG)
		ft_putchar(' ');
	if (stu->flag & DIESFLAG)
	{
		if (stu->conv == 'o' || stu->conv == 'O')
			ft_putchar('0');
		else if (stu->conv == 'x')
			ft_putstr("0x");
		else if (stu->conv == 'X')
			ft_putstr("0X");
	}
	if (stu->conv == 'p')
		ft_putstr("0x");
}

static void	ft_print_prcs(t_stu *stu, char *str)
{
	int j;

	if (stu->prcs > (int)ft_strlen(str))
	{
		j = stu->prcs - (int)ft_strlen(str);
		while (j)
		{
			ft_putchar('0');
			j--;
		}
	}
}

static void	ft_print_width(t_stu *stu, char *str, char c, int neg)
{
	int i;

	i = stu->width -
		(stu->prcs > (int)ft_strlen(str) ? stu->prcs : ft_strlen(str));
	if (neg || stu->flag & PLUSFLAG || stu->flag & ESPFLAG ||
			(stu->flag & DIESFLAG && (stu->conv == 'o' || stu->conv == 'O')))
		i--;
	if ((stu->flag & DIESFLAG && (stu->conv == 'x' || stu->conv == 'X')))
		i -= 2;
	if (stu->conv == 'p' && stu->width > (int)ft_strlen(str) + 2)
		i -= 2;
	else if (stu->conv == 'p')
		i = 0;
	if (*str == '0' && stu->prcs == 0)
		i++;
	while (i)
	{
		ft_putchar(c);
		i--;
	}
}

static void	ft_print_flag2(t_stu *stu, char *str, int neg)
{
	if ((stu->flag & ZEROFLAG) == 0)
	{
		ft_print_width(stu, str, ' ', neg);
		ft_print_pref(stu, neg);
		ft_print_prcs(stu, str);
		if (!(*str == '0' && stu->prcs == 0))
			ft_putstr(str);
	}
	else
	{
		ft_print_pref(stu, neg);
		ft_print_prcs(stu, str);
		ft_print_width(stu, str, '0', neg);
		if (!(*str == '0' && stu->prcs == 0))
			ft_putstr(str);
	}
}

void		ft_print_flag(t_stu *stu, char *str, int neg)
{
	if (stu->width > stu->prcs && stu->width > (int)ft_strlen(str))
	{
		if (stu->flag & MOINSFLAG)
		{
			ft_print_pref(stu, neg);
			ft_print_prcs(stu, str);
			if (!(*str == '0' && stu->prcs == 0))
				ft_putstr(str);
			ft_print_width(stu, str, ' ', neg);
		}
		else
			ft_print_flag2(stu, str, neg);
	}
	else
	{
		ft_print_pref(stu, neg);
		ft_print_prcs(stu, str);
		if (!(*str == '0' && stu->prcs == 0))
			ft_putstr(str);
	}
}
