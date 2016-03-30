/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_gru.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:29:26 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 15:33:41 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_gru(t_stu *stu)
{
	char	*str;
	char	*nb;

	nb = ft_itoa_base_ul((unsigned long)va_arg(stu->ap, unsigned long), 10);
	str = nb;
	if (stu->prcs >= 0)
		stu->flag = stu->flag & ~ZEROFLAG;
	stu->flag = stu->flag & ~PLUSFLAG;
	stu->flag = stu->flag & ~ESPFLAG;
	ft_print_flag(stu, str, 0);
	free(nb);
}
