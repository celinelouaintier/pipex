/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 14:33:57 by clouaint          #+#    #+#             */
/*   Updated: 2024/09/04 17:20:04 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int execve(const char *path, char const *argv[], char *envp[])
// #path: the path to our command type `which ls` and `which wc` in your terminal 
// you'll see the exact path to the commands' binaries
// # argv[]: the args the command needs, for ex. `ls -la` you can use your ft_split to obtain a char **
// like this { "ls", "-la", NULL } it must be null terminated
// # envp: the environmental variable you can simply retrieve it in your main (see below)
// and pass it onto execve, no need to do anything here in envp you'll see a line PATH which contains all possible
// paths to the commands' 

// récupérer PATH
char  *ft_getenv(const char *name, char **envp)
{
  size_t  name_len;
  int     i;

  i = 0;
  name_len = ft_strlen(name);
  while (envp[i])
  {
    if (ft_strncmp(envp[i], name, name_len) == 0 && envp[i][name_len] == '=')
      return (envp[i] + name_len + 1);
    i++;
  }
  return (NULL);
}

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}

// fonction pour reconstituer le path de la commande
char  *get_command_path(char *command, char **envp)
{
	char	**paths;
	char	*tmp_path;
	char	*full_path;
	int		i;
	char	*env_path;

	env_path = ft_getenv("PATH", envp);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path, ':');
	i = 0;
	while (paths[i])
	{
		tmp_path = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp_path, command);
		free(tmp_path);
		if (access(full_path, X_OK) == 0)
		{
			ft_free(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	ft_free(paths);
	return (NULL);
}
