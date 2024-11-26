/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruiz-ro <bruiz-ro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:46:13 by bruiz-ro          #+#    #+#             */
/*   Updated: 2024/11/26 13:59:17 by bruiz-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}

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

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**commands;
	char	**all_paths;
	char	*command_path;
	char	*current_path;

	all_paths = ft_split(get_envp("PATH", envp), ':');
	commands = ft_split(cmd, ' ');
	i = 0;
	while (all_paths[i])
	{
		current_path = ft_strjoin(all_paths[i], "/");
		command_path = ft_strjoin(current_path, commands[0]);
		free(current_path);
		if (access (command_path, F_OK | X_OK) == 0)
		{
			ft_free(all_paths);
			return (ft_free(commands), command_path);
		}
		free(command_path);
		i++;
	}
	ft_free(all_paths);
	ft_free(commands);
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
		ft_free(commands);
		return ;
	}
	if (execve(path, commands, envp) == -1)
	{
		ft_printf("Command not found %s\n", command[0]);
		perror("Error");
		ft_free(commands);
		free(path);
		exit(1);
	}
	ft_free(commands);
	free(path);
}
