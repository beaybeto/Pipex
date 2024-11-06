/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 20:01:52 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/11/06 20:32:36 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char *argv[])
{
	//2 fds, uno para extremo de escritura y el otro para extremo de lectura
	int fd[2];
	//parent es un valor de tipo pid_d que devuelve fork
	pid_t parent;
	//llamada a la funcion pipe
	pipe(fd);
	if (pipe(fd) == -1)
	{
		perror("error al crear el pipe");
		exit(1);
	}
	//llamada al fork (creacion del hijo)
	parent = fork();
	//estamos en el hijo
	if (parent == 0)
		child_process();
	//estamos en el padre
	else if (parent == 1)
		parent_process();
	//falla
	else
	{
		perror("error al hacer fork");
		exit(-1);
	}
	

	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[2], O_WRONLY);
	
	
	return (0);
}