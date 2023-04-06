/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:49:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/06 19:31:59 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_complete_data(char infile, char **env, t_data *data);
void	ft_pipex(int argc, char **argv, char **env);
void	ft_first_process(char **argv, char **env, int pipefd[2]);
void	ft_open_infile();
void	ft_here_doc();
void	ft_exec(char **argv, char **env, t_data *data);
void	ft_exit(t_data *data, int i);

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc;
	(void)argv;
	(void)env;
	ft_complete_data(argv[1], env, &data);
	ft_pipex(argc, argv, env, &data);
	return (0);
}

void	ft_complete_data(char infile, char **env, t_data *data)
{
	int	i;

	i = 0;
	if (ft_strncmp(infile, here_doc, 8))
		data->cmd = 2;
	else
		data->cmd = 3;
	while (env[i])
	{
		if (ft_strncmp(env[i], PATH=, 5))
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
	if (pipe(pipefd) == -1)
		ft_exit(data, EXIT_FAILURE);
	ft_first_process(argv, env, data);
}

void	ft_first_process(char **argv, char **env,  t_data *data)
{
	pid_t	pid;

	(void)argv;
	(void)env;
	pid = fork();
	if (pid == -1)
		ft_exit(data, EXIT_FAILURE);
	if (!pid)
	{
		if (data->cmd == 2)
			ft_open_infile();
		else
			ft_here_doc(data);

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

void	ft_exec(char **argv, char **env, t_data *data)
{
	char	*path;
	int		i;

	if (ft_strrchr(argv[data->cmd], '/') && !access(argv[data->cmd], X_OK))
		execve(data->cmd->content[0], data->cmd->content, env);
	f (ft_strrchr(argv[data->cmd], '/') && !access(argv[data->cmd], X_OK))
		execve(data->cmd->content[0], data->cmd->content, env);


}
	char	*path;
	int		i;

	i = 0;
	if (!access(data->cmd->content[0], X_OK))
		execve(data->cmd->content[0], data->cmd->content, env);
	while (data->path_list && data->path_list[i])
	{
		path = ft_strjoin_three(data->path_list[i], "/", data->cmd->content[0]);
		if (!path)
			ft_exit(data);
		if (!access(path, X_OK))
			execve(path, data->cmd->content, env);
		free(path);
		i++;
	}
	ft_exit(data);

void	ft_exit(t_data *data, int i)
{
	close(data->pipefd[0]);
	close(data->pipefd[0]);
	ft_free_split(data->path_list);
	exit (i)
}
