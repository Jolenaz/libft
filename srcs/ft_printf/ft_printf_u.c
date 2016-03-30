/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 16:37:54 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 15:33:00 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_u(t_stu *stu)
{
	char *str;
	char *nb;

	if (stu->mod == 1)
		nb = ft_itoa_base_ul((unsigned char)va_arg(stu->ap, unsigned int), 10);
	else if (stu->mod == 2)
		nb = ft_itoa_base_ul((unsigned short)va_arg(stu->ap, unsigned int), 10);
	else if (stu->mod == 0)
		nb = ft_itoa_base_ul((unsigned int)va_arg(stu->ap, unsigned int), 10);
	else
		nb = ft_itoa_base_ul((unsigned long)va_arg(stu->ap, unsigned long), 10);
	str = nb;
	if (stu->prcs >= 0)
		stu->flag = stu->flag & ~ZEROFLAG;
	stu->flag = stu->flag & ~PLUSFLAG;
	stu->flag = stu->flag & ~ESPFLAG;
	ft_print_flag(stu, str, 0);
	free(nb);
}
