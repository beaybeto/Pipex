/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:46:13 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/11/28 17:11:17 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_envp(char *name, char **envp)
{
	int		i;
	int		j;
	char	*path_name;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		path_name = ft_substr(envp[i], 0, j);
		if (ft_strcmp(path_name, name) == 0)
		{
			free(path_name);
			return (envp[i] + j + 1);
		}
		free(path_name);
		i++;
	}
	return (NULL);
}

int	protection(char **all_paths, char **commands)
{
	if (!commands || !commands[0])
	{
		ft_free(all_paths);
		return (1);
	}
	return (0);
}

char	*find_path(char **all_paths, char **commands)
{
	int		i;
	char	*current_path;
	char	*command_path;

	i = -1;
	while (all_paths[++i])
	{
		current_path = ft_strjoin(all_paths[i], "/");
		command_path = ft_strjoin(current_path, commands[0]);
		free(current_path);
		if (access (command_path, F_OK | X_OK) == 0)
		{
			ft_free(all_paths);
			ft_free(commands);
			return (command_path);
		}
		free(command_path);
	}
	ft_free(all_paths);
	ft_free(commands);
	return (NULL);
}

char	*get_path(char *cmd, char **envp)
{
	char	**commands;
	char	**all_paths;
	char	*command_path;

	all_paths = ft_split(get_envp("PATH", envp), ':');
	commands = ft_split(cmd, ' ');
	if (protection (all_paths, commands) == 1)
		return (NULL);
	if (access (cmd, F_OK | X_OK) == 0)
	{
		ft_free(all_paths);
		return (ft_free(commands), cmd);
	}
	command_path = find_path(all_paths, commands);
	if (command_path != NULL)
		return (command_path);
	return (NULL);
}

void	ft_exec(char *command, char **envp)
{
	char	**commands;
	char	*path;

	if (!command | !envp)
		return ;
	commands = ft_split(command, ' ');
	if (!commands)
		return ;
	path = get_path(commands[0], envp);
	if (!path)
	{
		write (2, "path not found", 14);
		ft_free(commands);
		exit (127);
	}
	if (execve(path, commands, envp) == -1)
	{
		perror("execve");
		ft_free(commands);
		free(path);
		exit(127);
	}
	ft_free(commands);
	free(path);
}
