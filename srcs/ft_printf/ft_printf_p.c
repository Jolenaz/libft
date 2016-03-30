/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:18:37 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 15:33:15 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_p(t_stu *stu)
{
	char *str;
	char *nb;

	nb = ft_itoa_base_ul((unsigned long)va_arg(stu->ap, void *), 16);
	str = nb;
	if (stu->prcs >= 0)
		stu->flag = stu->flag & ~ZEROFLAG;
	stu->flag = stu->flag & ~PLUSFLAG;
	stu->flag = stu->flag & ~ESPFLAG;
	ft_print_flag(stu, str, 0);
	free(nb);
}
