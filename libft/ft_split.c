/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:08:51 by clouaint          #+#    #+#             */
/*   Updated: 2024/05/23 17:50:01 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	count_substr(const char *str, char sep)
{
	int	count;
	int	in_word;

	in_word = 0;
	count = 0;
	while (*str)
	{
		if (*str != sep && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == sep)
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

static char	*get_next_substr(const char **s, char c)
{
	const char	*start;
	size_t		len;
	char		*res;
	size_t		i;

	while (**s && **s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = start[i];
		i++;
	}
	res[len] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (count_substr(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			res[i] = get_next_substr(&s, c);
			if (!res[i])
				return (NULL);
			i++;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
