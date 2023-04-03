/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:30:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/01 20:40:14 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*void	ft_exit(char **cmd, char **path_list)
{
	ft_free_split(cmd);
	ft_free_split(path_list);
	exit(EXIT_FAILURE);
}*/

void	ft_free_data(t_arg *data)
{
	ft_lstclear(&(data->cmd), ft_free_split);
	ft_free_split(data->path_list);
}

void	ft_exec(t_arg *data, char **env)
{
	char	*path;
	int		i;

	i = 0;
	if (!access(data->cmd->content[0], X_OK))
		execve(data->cmd->content[0], data->cmd->content, env);
	while (data->path_list[i])
	{
		path = ft_strjoin_three(data->path_list[i], "/", data->cmd->content[0]);
		if (!path)
			exit(EXIT_FAILURE);
		if (!access(path, X_OK))
			execve(path, data->cmd->content, env);
		free(path);
		i++;
	}
	ft_printf("pipex: command not found: %s\n", data->cmd->content[0]);
	exit(1);
}

int	ft_process(t_arg *data, char **env)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd;
	int		fd2;
	int		ftd[2];
	t_list	*tmp;

	pid = fork();
	if (!pid)
	{
		pipe(ftd);
		fd = open("test", O_CREAT | O_WRONLY, 0644);
		pid2 = fork();
		if (!pid2)
		{
			fd2 = open("Makefile", O_RDONLY);
			dup2(fd2, STDIN_FILENO);
			close (fd2);
			close(ftd[0]);
			dup2(ftd[1], STDOUT_FILENO);
			close(ftd[1]);
			ft_exec(data, env);
		}
		else
		{
			tmp = data->cmd;
			data->cmd = data->cmd->next;
			ft_lstdelone(tmp, ft_free_split);
			close(ftd[1]);
			dup2(ftd[0], STDIN_FILENO);
			close(ftd[0]);
			dup2(fd, STDOUT_FILENO);
			close (fd);
			ft_exec(data, env);
		}
	}
	else
		waitpid(pid, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	t_arg	data;

	if (argc < 1)
		return (EXIT_FAILURE);
	parsing_pipex(&data, argc, argv, env);
	ft_process(&data, env);
	ft_free_data(&data);
	return (EXIT_SUCCESS);
}
