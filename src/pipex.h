/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:11:55 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/11/21 20:19:06 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
//for execve, fork functions
# include <unistd.h>
//for free function and NULL
# include <stdlib.h>
//for open function
# include <fcntl.h>
//to define pid_t
# include <sys/types.h>
# include <sys/wait.h>

void	ft_free(char **str);
int		ft_strcmp(char *s1, char *s2);
char	*get_envp(char *name, char **envp);
char	*get_path(char *cmd, char **envp);
void	ft_exec(char *command, char **envp);
void	child_process(char *argv[], int *fd, char **envp);
void	parent_process(char *argv[], int *fd, char **envp);

#endif