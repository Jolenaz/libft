/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_grd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 08:03:21 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 15:33:57 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_grd(t_stu *stu)
{
	char	*str;
	char	*nb;
	int		neg;

	neg = 0;
	nb = ft_strdup(ft_itoa_base(va_arg(stu->ap, long int), 10));
	str = nb;
	if (*str == '-')
	{
		neg = 1;
		str++;
	}
	if (stu->prcs >= 0)
		stu->flag = stu->flag & ~ZEROFLAG;
	ft_print_flag(stu, str, neg);
	free(nb);
}
