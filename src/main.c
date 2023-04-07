/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:49:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/07 17:25:19 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_complete_data(char *infile, char **env, t_data *data);
void	ft_pipex(int argc, char **argv, char **env, t_data *data);
void	ft_first_process(char **argv, char **env, t_data *data);
void	ft_open_infile(void);
void	ft_here_doc(t_data *data);
void	ft_exec(char **argv, char **cmd, char **env, t_data *data);
void	ft_exit(t_data *data, int i);

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	ft_complete_data(argv[1], env, &data);
	ft_pipex(argc, argv, env, &data);
	return (0);
}

void	ft_complete_data(char *infile, char **env, t_data *data)
{
	int	i;

	i = 0;
	if (ft_strncmp(infile, "here_doc", 8))
		data->cmd = 2;
	else
		data->cmd = 3;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			data->path_list = ft_split(env[i] + 5, ':');
			if (!data->path_list)
				exit(EXIT_FAILURE);
			return ;
		}
		i++;
	}
	data->path_list = NULL;
}

void	ft_pipex(int argc, char **argv, char **env, t_data *data)
{
	(void)argc;
	ft_first_process(argv, env, data);
}

void	ft_first_process(char **argv, char **env, t_data *data)
{
	pid_t	pid;
	char	**cmd;

	pid = fork();
	if (pid == -1)
		ft_exit(data, EXIT_FAILURE);
	if (!pid)
	{
		if (data->cmd == 2)
			ft_open_infile();
		else
			ft_here_doc(data);
		cmd = ft_split(argv[data->cmd], ' ');
		ft_exec(argv, cmd, env, data);
	}
}

void	ft_open_infile(void)
{
	return ;
}

void	ft_here_doc(t_data *data)
{
	ft_exit(data, EXIT_FAILURE);
}

void	ft_exec(char **argv, char **cmd, char **env, t_data *data)
{
	char	*path;
	int		i;

	i = 0;
	if (ft_strchr(cmd[0], '/') && !access(cmd[0], X_OK))
		execve(cmd[0], cmd, env);
	else if (ft_strchr(cmd[0], '/') && !access(cmd[0], F_OK))
		ft_printf("%s: permission denied: %s\n", argv[0], cmd[0]);
	else if (ft_strchr(cmd[0], '/'))
		ft_printf("%s: no such file or directory: %s\n", argv[0], cmd[0]);
	else
	{
		while (data->path_list && data->path_list[i])
		{
			path = ft_strjoin_three(data->path_list[i], "/", cmd[0]);
			if (!path)
				ft_exit(data, EXIT_FAILURE);
			if (!access(path, X_OK))
				execve(path, cmd, env);
			free(path);
			i++;
		}
		ft_printf("%s: command not found: %s\n", argv[0], cmd[0]);
	}
	ft_exit(data, EXIT_FAILURE);
}

void	ft_exit(t_data *data, int i)
{
	close(data->pipefd[0]);
	close(data->pipefd[0]);
	ft_free_split(data->path_list);
	exit (i);
}
