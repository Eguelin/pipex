/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:44:29 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/03 18:48:37 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_first_process(t_arg *data, char **env, int pipefd[2]);
static void	ft_last_process(t_arg *data, char **env, int pipefd[2]);
static void	ft_exec(t_arg *data, char **env);

int	ft_process(t_arg *data, char **env)
{
	int		pipefd[2];
	t_list	*tmp;

	if (pipe(pipefd))
		ft_exit(data);
	ft_first_process(data, env, pipefd);
	tmp = data->cmd;
	data->cmd = data->cmd->next;
	ft_lstdelone(tmp, ft_free_split);
	ft_last_process(data, env, pipefd);
	return (0);
}

static void	ft_first_process(t_arg *data, char **env, int pipefd[2])
{
	pid_t	pid;
	int	fd;

	pid = fork();
	if (pid == -1)
		ft_exit(data);
	if (!pid)
	{
		fd = open(data->infile, O_RDONLY);
		if (fd == -1)
		{
			close(pipefd[0]);
			close(pipefd[1]);
			ft_exit(data);
		}
		dup2(fd, STDIN_FILENO);
		close (fd);
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		ft_exec(data, env);
	}
}

/*ft_middel_process(&data, env);*/

static void	ft_last_process(t_arg *data, char **env, int pipefd[2])
{
	pid_t	pid;
	int	fd;

	pid = fork();
	if (pid == -1)
		ft_exit(data);
	if (!pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		close(pipefd[0]);
		fd = open(data->outfile, O_CREAT | O_WRONLY, 0644);
		if (fd == -1)
			ft_exit(data);
		dup2(fd, STDOUT_FILENO);
		close (fd);
		ft_exec(data, env);
	}
	else
	{
		close(pipefd[1]);
		close(pipefd[0]);
		waitpid(pid, NULL, 0);
	}
}

static void	ft_exec(t_arg *data, char **env)
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
}
