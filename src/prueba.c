/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:01:52 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/11/11 20:44:50 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[])
{
	int fd[2];
	int	status;
	
	int	infile;
	int outfile;
	
	pid_t parent;
	pipe(fd);
	if (pipe(fd) == -1)
	{
		perror("error al crear el pipe");
		exit(1);
	}
	parent = fork();
	if (parent == 0)
	{
		//child_process();
		infile = open(argv[1], O_RDONLY);
		if(infile == -1)
			perror("error en la entrada");
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close (fd[0]);
		close(infile);
		execve(path, ft_split(cmd1, ' '), env);
	}
	else if (parent > 0)
	{
		//parent_process();
		outfile = open(argv[5], O_WRONLY);
		if(outfile == -1)
			perror("error en la salida");
		waitpid(-1, &status, 0);
		dup2(outfile, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(outfile);
		execve(path, ft_split(cmd2, ' '), env);
	}
	else
	{
		perror("error al hacer fork");
		exit(-1);
	}

	fd[1] = open(argv[2], O_WRONLY);
	
	return (0);
}