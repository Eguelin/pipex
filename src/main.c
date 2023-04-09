/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:49:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/09 20:53:20 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		ft_pipex(char **argv, char **env, t_data *data);
pid_t	ft_process(char **argv, char **env, t_data *data);
void	ft_exec(char **argv, char **env, t_data *data);

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		exit_ft;

	exit_ft = 0;
	data.path_list = NULL;
	if (argc <= 3)
	{
		ft_printf("%s: parse error near `\\n'\n", argv[0]);
		return (EXIT_FAILURE);
	}
	if (ft_strlen(argv[1]) == 8 && !ft_strncmp(argv[1], "here_doc", 8))
		ft_here_doc(&data);
	else
		ft_dup(ft_open_infile(argv, &data), STDIN_FILENO, &data);
	exit_ft = ft_pipex(argv, env, &data);
	ft_free_split(data.path_list);
	close(0);
	close(1);
	close(2);
	return (exit_ft);
}

int	ft_pipex(char **argv, char **env, t_data *data)
{
	pid_t	pid;
	int		exit_ft;

	exit_ft = 0;
	ft_path_list(env, data);
	while (argv[data->cmd + 1])
	{
		if (argv[data->cmd + 2])
			if (pipe(data->pipefd) == -1)
				ft_exit(data, EXIT_FAILURE);
		pid = ft_process(argv, env, data);
		data->cmd++;
		if (argv[data->cmd +1])
		{
			close(data->pipefd[1]);
			ft_dup(data->pipefd[0], STDIN_FILENO, data);
		}
	}
	waitpid(pid, &exit_ft, 0);
	return (WEXITSTATUS(exit_ft));
}

pid_t	ft_process(char **argv, char **env, t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit(data, EXIT_FAILURE);
	if (!pid)
	{
		if (argv[data->cmd + 2] && (data->cmd == 2 || (ft_strlen(argv[1]) == 8 \
		&& !ft_strncmp(argv[1], "here_doc", 8) && data->cmd == 3)))
			close(data->pipefd[0]);
		if (data->cmd == 2 && access(argv[1], R_OK))
		{
			if (argv[data->cmd + 2])
				close(data->pipefd[1]);
			ft_exit(data, EXIT_FAILURE);
		}
		if (argv[data->cmd + 2])
			ft_dup(data->pipefd[1], STDOUT_FILENO, data);
		else
			ft_dup(ft_open_outfile(argv, data), STDOUT_FILENO, data);
		ft_exec(argv, env, data);
	}
	return (pid);
}

void	ft_exec(char **argv, char **env, t_data *data)
{
	char	*path;
	char	**cmd;

	if (!argv[data->cmd][0])
	{
		ft_printf("%s: permission denied: %s\n", argv[0], argv[data->cmd]);
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

void	ft_exit(t_data *data, int i)
{
	ft_free_split(data->path_list);
	close(0);
	close(1);
	close(2);
	exit (i);
}
