/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 09:06:38 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/07 14:02:14 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_power(int a, int b)
{
	int tmp;

	tmp = a;
	if (b == 0)
		return (1);
	else if (b < 0)
		return (0);
	while (b)
	{
		a = a * tmp;
		b--;
	}
	return (a);
}
