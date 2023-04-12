/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:49:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/12 15:00:21 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_pipex(char **argv, char **env, t_data *data);
void	ft_process(char **argv, char **env, t_data *data);
void	ft_exec(char **argv, char **env, t_data *data);

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		exit_ft;

	ft_set_data(argv, &data);
	if (argc <= 3 || (argc <= 4 && data.here_doc))
	{
		ft_printf("%s: Syntax error: newline unexpected\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (data.here_doc)
	{
		if (pipe(data.pipefd) == -1)
			exit(EXIT_FAILURE);
		ft_here_doc(argv, &data);
		ft_close(&data.pipefd[1]);
		ft_dup(data.pipefd[0], STDIN_FILENO, &data);
	}
	else
		ft_dup(ft_open_infile(argv), STDIN_FILENO, &data);
	exit_ft = ft_pipex(argv, env, &data);
	close(0);
	return (exit_ft);
}

int	ft_pipex(char **argv, char **env, t_data *data)
{
	int		exit_ft;

	exit_ft = 0;
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
			ft_exit(data, EXIT_FAILURE);
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
		ft_exit(data, EXIT_FAILURE);
	}
	cmd = ft_split(argv[data->cmd], ' ');
	if (!cmd)
		ft_exit(data, EXIT_FAILURE);
	path = ft_relative_path(argv, cmd, data);
	if (!path)
		path = ft_absolute_path(argv, cmd, data);
	execve(path, cmd, env);
}
