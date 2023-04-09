/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:24:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/09 20:48:16 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_infile(char **argv, t_data *data)
{
	int	fd;

	data->cmd = 2;
	if (!argv[1][0] || access(argv[1], F_OK))
	{
		ft_printf("%s: no such file or directory: %s\n", argv[0], argv[1]);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: permission denied: %s\n", argv[0], argv[1]);
		return (-1);
	}
	return (fd);
}

int	ft_open_outfile(char **argv, t_data *data)
{
	int	fd;

	if (!argv[data->cmd + 1][0])
	{
		ft_printf("%s: no such file or directory: %s\n", argv[0], \
		argv[data->cmd + 1]);
		ft_exit(data, EXIT_FAILURE);
	}
	else if (!access(argv[data->cmd + 1], F_OK))
	{
		if (access(argv[data->cmd + 1], W_OK))
		{
			ft_printf("%s: permission denied: %s\n", argv[0], \
			argv[data->cmd + 1]);
			ft_exit(data, EXIT_FAILURE);
		}
		unlink(argv[data->cmd + 1]);
	}
	fd = open(argv[data->cmd + 1], O_CREAT | O_WRONLY, 0755);
	if (fd == -1)
		ft_exit(data, EXIT_FAILURE);
	return (fd);
}

void	ft_dup(int fd, int fd2, t_data *data)
{
	if (fd == -1)
		return ;
	if (dup2(fd, fd2) == -1)
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
