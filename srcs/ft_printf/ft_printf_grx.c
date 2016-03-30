/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_grx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:46:29 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 15:33:33 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_upper(char *str)
{
	char *c;

	c = str;
	while (*c)
	{
		if (*c >= 'a' && *c <= 'z')
			(*c) -= 32;
		c++;
	}
}

void		ft_printf_grx(t_stu *stu)
{
	char *str;
	char *nb;

	if (stu->mod == 1)
		nb = ft_itoa_base_ul((unsigned char)va_arg(stu->ap, unsigned int), 16);
	else if (stu->mod == 2)
		nb = ft_itoa_base_ul((unsigned short)va_arg(stu->ap, unsigned int), 16);
	else if (stu->mod == 0)
		nb = ft_itoa_base_ul((unsigned int)va_arg(stu->ap, unsigned int), 16);
	else
		nb = ft_itoa_base_ul((unsigned long)va_arg(stu->ap, unsigned long), 16);
	str = nb;
	if (stu->prcs >= 0)
		stu->flag = stu->flag & ~ZEROFLAG;
	if (*nb == '0')
		stu->flag = stu->flag & ~DIESFLAG;
	stu->flag = stu->flag & ~PLUSFLAG;
	stu->flag = stu->flag & ~ESPFLAG;
	ft_upper(str);
	ft_print_flag(stu, str, 0);
	free(nb);
}
