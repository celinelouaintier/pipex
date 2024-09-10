/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 11:16:45 by clouaint          #+#    #+#             */
/*   Updated: 2024/06/11 10:56:54 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

// continue de lire le fichier jusqu'a ce qu'il trouve un \n.
// Meme si le BUFFER_SIZE est enorme, avec strchr
// on prend en compte le 1er \n. On pourra donc couper tout ce qu'il
// y a apres ensuite.
char	*read_line(int fd, char *stash, char *buffer)
{
	int	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stash);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

// nettoie la ligne recuperee en enlevant ce qu'il y a apres le \n
// Avant de return, on doit rajouter le caractere nul apres le \n
// C'est le premier caractere de la chaine pointee par new_line qu'il
// faut verifier : !*new_line ET PAS !new_line
char	*extract_new_line(char *line)
{
	char	*new_line;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	new_line = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!*new_line)
		return (NULL);
	line[i + 1] = '\0';
	return (new_line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	line = read_line(fd, stash, buffer);
	free(buffer);
	if (!line)
	{
		free(line);
		return (NULL);
	}
	stash = extract_new_line(line);
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open(argv[1], O_RDONLY);
// 	// printf("%s", line = get_next_line(fd));
// 	// 	free(line);
// 	// printf("%s", get_next_line(fd));
// 	// 	free(line);
// 	// printf("%s", get_next_line(fd));
// 	// free(line);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 					printf("%s", line);
// 		free (line);
// 	}
// 	return (0);
// }
