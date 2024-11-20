/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:31:39 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/11/20 21:20:17 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv[], int *fd, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("error opening infile");
		exit(1);
	}
	dup2 (infile, STDIN_FILENO);
	dup2 (fd[1], STDOUT_FILENO);
	close (fd[0]);
	close (infile);
	ft_exec (argv[2], envp);
}

void	parent_process(char *argv[], int *fd, char **envp)
{
	int	outfile;
	int	status;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		perror ("error opening outfile");
		exit (1);
	}
	waitpid(-1, &status, 0);
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close (fd[1]);
	close (outfile);
	ft_exec(argv[3], envp);
}

int	main(int argc, char*argv[], char**envp)
{
	int		fd[2];
	pid_t	parent;

	if (argc != 5)
	{
		ft_putendl_fd("command must be: ./pipex infile cmd1 cmd2 outfile", 2);
		exit (1);
	}
	if (pipe(fd) == -1)
	{
		perror("error creating the pipe");
		exit(1);
	}
	parent = fork();
	if (parent == 0)
		child_process(argv, fd, envp);
	if (parent > 0)
		parent_process(argv, fd, envp);
	else
	{
		perror("error al hacer el fork");
		exit(1);
	}
	return (0);
}
