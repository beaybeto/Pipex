/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 20:11:55 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/11/18 20:33:23 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
//to define pid_t
# include <sys/types.h>
# include <sys/wait.h>

void	ft_free(char **str);
char	*get_envp(char *name, char **envp);
char	*get_path(char *cmd, char **envp);
void	ft_exec(char *command, char **envp);
void	child_process(char *argv[], int *fd, char **envp);
void	parent_process(char *argv[], int *fd, char **envp);

#endif