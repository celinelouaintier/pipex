/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 14:49:44 by clouaint          #+#    #+#             */
/*   Updated: 2024/05/22 17:49:38 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*new;
	size_t	i;

	i = 0;
	if (elementSize == 0 || elementCount == 0)
		new = malloc(0);
	else
		new = malloc(elementCount * elementSize);
	if (!new)
		return (NULL);
	while (*(unsigned char *)(new + i))
	{
		*(unsigned char *)(new + i) = 0;
		i++;
	}
	return (new);
}
