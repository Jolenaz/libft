/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 16:35:55 by jbelless          #+#    #+#             */
/*   Updated: 2015/11/30 17:13:44 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstaddback(t_list **alst, t_list *newlst)
{
	t_list *tmp;

	tmp = *alst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = newlst;
}
