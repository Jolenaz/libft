/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbelless <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:47:17 by jbelless          #+#    #+#             */
/*   Updated: 2015/11/24 17:25:32 by jbelless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *dst;

	dst = NULL;
	dst = (char*)malloc(sizeof(char) * (strlen(src) + 1));
	if (dst == NULL)
		return (NULL);
	return (ft_strcpy(dst, src));
}
