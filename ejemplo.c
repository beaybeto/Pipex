/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ejemplo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:44:35 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/11/12 19:49:52 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*#include <string.h>
//para la funcion wait
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd[2];
	pid_t pidC;
	char buff[10];
	int	num;
	//status sirve para la funcion wait
	int	status;

	pipe(fd);
	
	if (pipe(fd) == -1) 
	{
        perror("Error al crear el pipe");
        exit(1);
    }
	
	pidC = fork();
	
	if (pidC == -1) 
	{
        perror("Error al hacer fork");
        exit(1);
	}
	if (pidC == 0)
	{
		close (fd[0]);
		write (fd[1], "mensaje", 7);
		close (fd[1]);
		exit(0);
	}
	else
	{
		wait(&status);
		printf("proceso hijo terminado\n");
		close (fd[1]);
		num = read(fd[0], buff, sizeof(buff));
		printf("padre lee %d bytes: %s \n", num, buff);
		close (fd[0]);
	}
	return (0);
}*/
int	main(int argc, char **argv)
{
	int	i;
	int	j;

	j = argc - 1;
	while (j >= 1)
	{
		i = 0;
		while (argv[j][i] != '\0')
		{
			write (1, &argv[j][i], 1);
			i++;
		}
		write (1, "\n", 1);
		j--;
	}
	return (0);
}