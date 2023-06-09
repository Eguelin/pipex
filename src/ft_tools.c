/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:30:23 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/14 13:23:45 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_set_data(t_data *data)
{
	data->cmd = 2;
	data->pipefd[0] = -1;
	data->pipefd[1] = -1;
	data->pid = 1;
	data->path_list = NULL;
}

void	ft_dup(int fd, int fd2, t_data *data)
{
	if (fd == -1)
		return ;
	if (dup2(fd, fd2) == -1)
	{
		close(fd);
		if (fd == data->pipefd[0])
			data->pipefd[0] = -1;
		else if (fd == data->pipefd[1])
			data->pipefd[1] = -1;
		ft_exit(data, EXIT_FAILURE);
	}
	close(fd);
	if (fd == data->pipefd[0])
		data->pipefd[0] = -1;
	else if (fd == data->pipefd[1])
		data->pipefd[1] = -1;
}

void	ft_close(int *fd)
{
	if (*fd != -1)
	{
		close(*fd);
		*fd = -1;
	}
}

void	ft_exit(t_data *data, int i)
{
	ft_free_split(data->path_list);
	ft_close(&data->pipefd[0]);
	ft_close(&data->pipefd[1]);
	close(0);
	if (!data->pid)
		close(1);
	exit (i);
}
