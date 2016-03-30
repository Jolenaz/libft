/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:00:15 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 15:33:23 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_o(t_stu *stu)
{
	char *str;
	char *nb;

	if (stu->mod == 1)
		nb = ft_itoa_base_ul((unsigned char)va_arg(stu->ap, unsigned int), 8);
	else if (stu->mod == 2)
		nb = ft_itoa_base_ul((unsigned short)va_arg(stu->ap, unsigned int), 8);
	else if (stu->mod == 0)
		nb = ft_itoa_base_ul((unsigned int)va_arg(stu->ap, unsigned int), 8);
	else
		nb = ft_itoa_base_ul((unsigned long)va_arg(stu->ap, unsigned long), 8);
	str = nb;
	if (stu->prcs > 0)
	{
		stu->flag = stu->flag & ~ZEROFLAG;
		stu->flag = stu->flag & ~DIESFLAG;
	}
	else if (stu->prcs == -1 && *str == '0')
		stu->flag = stu->flag & ~DIESFLAG;
	stu->flag = stu->flag & ~PLUSFLAG;
	stu->flag = stu->flag & ~ESPFLAG;
	ft_print_flag(stu, str, 0);
	free(nb);
}
