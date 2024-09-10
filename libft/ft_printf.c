/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-05 14:09:54 by clouaint          #+#    #+#             */
/*   Updated: 2024-07-05 14:09:54 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		len += ft_printchar('-');
		len += ft_printchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		len += ft_printchar('-');
		nb *= (-1);
	}
	if (nb < 10)
	{
		len += ft_printchar(nb + '0');
	}
	else
	{
		len += ft_putnbr(nb / 10);
		len += ft_printchar(nb % 10 + '0');
	}
	return (len);
}

int	check_format(va_list params, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = len + ft_printchar(va_arg(params, int));
	else if (c == 's')
		len = len + ft_printstr(va_arg(params, char *));
	else if (c == 'd' || c == 'i')
		len = len + ft_putnbr(va_arg(params, int));
	else if (c == '%')
		len = len + ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	params;
	int		len;

	va_start(params, str);
	i = 0;
	len = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = len + check_format(params, str[i + 1]);
			i++;
		}
		else
			len = len + ft_printchar(str[i]);
		i++;
	}
	va_end(params);
	return (len);
}