/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_singleton.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:50:05 by jbelless          #+#    #+#             */
/*   Updated: 2016/03/18 16:23:46 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_singleton(int i)
{
	static int sauv = 0;

	if (i == 0)
		sauv = 0;
	else if (i == 1)
		sauv++;
	return (sauv);
}
