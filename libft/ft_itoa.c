/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:04:48 by clouaint          #+#    #+#             */
/*   Updated: 2024/05/23 15:44:33 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	find_size(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len ++;
		n /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nbr;

	nbr = n;
	len = find_size(nbr);
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		nbr = -nbr;
	}
	else if (nbr == 0)
		res[0] = '0';
	res[len] = '\0';
	while (nbr != 0)
	{
		res[--len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (res);
}
