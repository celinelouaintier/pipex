/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clouaint <clouaint@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:36:01 by clouaint          #+#    #+#             */
/*   Updated: 2024/09/04 17:21:26 by clouaint         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// TODO : creer deux enfants
void	exec(char *cmd, char *envp[])
{
  char  **av;
  char  *path;

  av = ft_split(cmd, ' ');
  path = get_command_path(av[0], envp);
  if (execve(path, av, envp) == -1)
  {
	perror("Error: execve failed");
	free(path);
	ft_free(av);
	exit(1);
  }
}

void	process_pipes(char	*cmd, char *envp[], char **av, int ac)
{
	int		fd;
	pid_t	parent; //stock des identifiants de processus (PID) pour reconnaître le fils du père (c'est la fonction fork() qui renvoie le pid)
	int		pipe_fd[2]; //tableau pour contenir les deux fd créés par pipe(). end[0](parent) pour lire dans le pipe / end[1](fils) pour écrire dans le pipe

	pipe(pipe_fd); // créé un canal pour la communication entre deux processus. end[0] = lecture end[1] = ecriture
	parent = fork(); // crée un nouveau processus (fils) en dupliquant le processus courant (parent). -1 = erreur, 0 = process fils, >0 = process parent.
	if (!parent) // fork = 0 DONC process fils	
	{
		close(pipe_fd[0]); //ferme le bout de lecture non utilisé (parent)
		fd = open(av[1], O_RDONLY);
		dup2(pipe_fd[1], STDOUT_FILENO); // redirige la sortie qui est normalement sur la console, dans le pipe
		dup2(fd, STDIN_FILENO); // redirige l'entree standard (ce que j'ecris dans le terminal) vers fd ()
		exec(cmd, envp);
	}
	else
	{
		close(pipe_fd[1]);
		fd = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		dup2(pipe_fd[0], STDIN_FILENO); // prend la donnee du pipe
		dup2(fd, STDOUT_FILENO); // change la sortie vers le second fd
		waitpid(parent, NULL, 0);
	}
}

// int dup2(int oldfd, int newfd)
// cette fonction écrit ce qu'il y a dans le printf (sortie standard) dans le fichier texte (sortie fd)
int main(int ac, char **av, char *envp[])
{
	int		i;
    
	i = 3;
    if (ac >= 5)
    {
		process_pipes(av[2], envp, av, ac);
		while (i < ac - 2)
		{
			process_pipes(av[i], envp, av, ac);
			i++;
        }
		exec(av[i], envp);
    }
	return (0);
}
