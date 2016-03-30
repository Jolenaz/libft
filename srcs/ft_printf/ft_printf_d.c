/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/21 15:10:05 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/29 15:34:03 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_d(t_stu *stu)
{
	char	*str;
	char	*nb;
	int		neg;

	neg = 0;
	if (stu->mod == 0)
		nb = ft_strdup(ft_itoa_base((int)va_arg(stu->ap, int), 10));
	else if (stu->mod == 1)
		nb = ft_strdup(ft_itoa_base((char)va_arg(stu->ap, int), 10));
	else if (stu->mod == 2)
		nb = ft_strdup(ft_itoa_base((short)va_arg(stu->ap, int), 10));
	else if (stu->mod == 3)
		nb = ft_strdup(ft_itoa_base((long)va_arg(stu->ap, long int), 10));
	else
		nb = ft_strdup(ft_itoa_base((long)va_arg(stu->ap, long long int), 10));
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
