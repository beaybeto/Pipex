/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:31:39 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/11/28 19:09:19 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char *argv[], int *fd, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("Error opening infile");
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
		perror ("Error opening outfile");
		exit (1);
	}
	waitpid(-1, &status, WNOHANG);
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

	if (envp[0] == NULL)
		return (1);
	if (argc != 5)
	{
		ft_putendl_fd("Error! Commands not valid", 2);
		exit (1);
	}
	if (pipe(fd) == -1)
	{
		perror("Error creating the pipe");
		exit(1);
	}
	parent = fork();
	if (parent == 0)
		child_process(argv, fd, envp);
	if (parent < 0)
	{
		perror("Error when making fork");
		exit(1);
	}
	parent_process(argv, fd, envp);
	return (0);
}
