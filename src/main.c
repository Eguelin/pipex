/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:49:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/08 14:05:27 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipex(int argc, char **argv, char **env, t_data *data);
void	ft_first_process(char **argv, char **env, t_data *data);
void	ft_open_infile(t_data *data);
void	ft_here_doc(t_data *data);
void	ft_exit(t_data *data, int i);

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		i;

	i = 0;
	ft_path_list(env, &data);
	ft_pipex(argc, argv, env, &data);
	ft_free_split(data.path_list);
	close(0);
	close(1);
	close(2);
	waitpid(-1, &i, 0);
	return (WEXITSTATUS(i));
}

void	ft_pipex(int argc, char **argv, char **env, t_data *data)
{
	(void)argc;
	ft_first_process(argv, env, data);
}

void	ft_first_process(char **argv, char **env, t_data *data)
{
	pid_t	pid;
	char	*path;
	char	**cmd;

	pid = fork();
	if (pid == -1)
		ft_exit(data, EXIT_FAILURE);
	if (!pid)
	{
		if (ft_strncmp(argv[1], "here_doc", 8))
			ft_open_infile(data);
		else
			ft_here_doc(data);
		cmd = ft_split(argv[data->cmd], ' ');
		if (!cmd)
			ft_exit(data, EXIT_FAILURE);
		path = ft_relative_path(argv, cmd, data);
		if (!path)
			path = ft_absolute_path(argv, cmd, data);
		execve(path, cmd, env);
	}
}

void	ft_open_infile(t_data *data)
{
	data->cmd = 2;
	return ;
}

void	ft_here_doc(t_data *data)
{
	data->cmd = 3;
	ft_exit(data, EXIT_FAILURE);
}

void	ft_exit(t_data *data, int i)
{
	ft_free_split(data->path_list);
	close(0);
	close(1);
	close(2);
	exit (i);
}
