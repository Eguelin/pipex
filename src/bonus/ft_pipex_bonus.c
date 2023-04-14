/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:25:46 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/14 15:18:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_pipex(char **argv, char **env, t_data *data)
{
	int	exit_ft;
	int	wait;

	exit_ft = 0;
	wait = 0;
	ft_path_list(env, data);
	while (argv[data->cmd + 1])
	{
		if (argv[data->cmd + 2] && pipe(data->pipefd) == -1)
			ft_exit(data, EXIT_FAILURE);
		ft_process(argv, env, data);
		data->cmd++;
		if (argv[data->cmd + 1])
		{
			ft_close(&data->pipefd[1]);
			ft_dup(data->pipefd[0], STDIN_FILENO, data);
		}
	}
	waitpid(data->pid, &exit_ft, 0);
	close(0);
	while (wait != -1)
		wait = waitpid(-1, NULL, 0);
	ft_free_split(data->path_list);
	return (WEXITSTATUS(exit_ft));
}

void	ft_process(char **argv, char **env, t_data *data)
{
	data->pid = fork();
	if (data->pid == -1)
		ft_exit(data, EXIT_FAILURE);
	if (!data->pid)
	{
		ft_close(&data->pipefd[0]);
		if (data->cmd == 2 && access(argv[1], R_OK))
		{
			ft_close(&data->pipefd[1]);
			ft_exit(data, 126);
		}
		if (argv[data->cmd + 2])
			ft_dup(data->pipefd[1], STDOUT_FILENO, data);
		else
			ft_dup(ft_open_outfile(argv, data), STDOUT_FILENO, data);
		ft_exec(argv, env, data);
	}
}

void	ft_exec(char **argv, char **env, t_data *data)
{
	char	*path;
	char	**cmd;

	if (!argv[data->cmd][0])
	{
		ft_printf("%s: %s: Permission denied\n", argv[0], argv[data->cmd]);
		ft_exit(data, 127);
	}
	cmd = ft_split(argv[data->cmd], ' ');
	if (!cmd)
		ft_exit(data, EXIT_FAILURE);
	path = ft_check_absolute_path(argv, cmd, data);
	if (!path)
		path = ft_check_relative_path(argv, cmd, data);
	execve(path, cmd, env);
}
