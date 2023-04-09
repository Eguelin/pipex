/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:24:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/09 15:46:29 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_open_infile(char **argv, t_data *data)
{
	int	fd;

	data->cmd = 2;
	if (!argv[1][0] || access(argv[1], F_OK))
	{
		ft_printf("%s: no such file or directory: %s\n", argv[0], argv[1]);
		return ;
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: permission denied: %s\n", argv[0], argv[1]);
		return ;
	}
	ft_dup_fd_stdin(fd, data);
}

void	ft_open_outfile(char **argv, t_data *data)
{
	int	fd;

	if (!argv[data->cmd + 1][0])
	{
		ft_printf("%s: no such file or directory: %s\n", argv[0], \
		argv[data->cmd + 1]);
		ft_exit(data, EXIT_FAILURE);
	}
	if (!access(argv[data->cmd + 1], F_OK))
		unlink(argv[data->cmd + 1]);
	fd = open(argv[data->cmd + 1], O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
	{
		ft_printf("%s: permission denied: %s\n", argv[0], argv[data->cmd + 1]);
		ft_exit(data, EXIT_FAILURE);
	}
	ft_dup_fd_stdout(fd, data);
}

void	ft_dup_fd_stdin(int fd, t_data *data)
{
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		ft_exit(data, EXIT_FAILURE);
	}
	close(fd);
}

void	ft_dup_fd_stdout(int fd, t_data *data)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		ft_exit(data, EXIT_FAILURE);
	}
	close(fd);
}

void	ft_here_doc(t_data *data)
{
	data->cmd = 3;
	exit(EXIT_FAILURE);
}
