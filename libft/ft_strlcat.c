/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:04:52 by clouaint          #+#    #+#             */
/*   Updated: 2024/05/23 18:09:26 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	lensrc = ft_strlen(src);
	lendst = ft_strlen(dest);
	i = 0;
	if (size < lendst || size == 0)
		return (size + lensrc);
	while (src[i] && i + lendst < size - 1)
	{
		dest[lendst + i] = src[i];
		i++;
	}
	dest[lendst + i] = 0;
	return (lendst + lensrc);
}
