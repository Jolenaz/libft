/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:19:58 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/31 10:58:03 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_gro(t_stu *stu)
{
	char *str;
	char *nb;

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
	ft_printf_flag(stu, str, 0);
	free(nb);
}
