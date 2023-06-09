/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:24:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/14 17:31:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_open_infile(char **argv)
{
	int	fd;

	if (!argv[1][0] || access(argv[1], F_OK))
	{
		ft_printf("%s: %s: No such file or directory\n", argv[0], argv[1]);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: %s: Permission denied\n", argv[0], argv[1]);
		return (-1);
	}
	return (fd);
}

int	ft_open_outfile(char **argv, t_data *data)
{
	int	fd;

	if (!argv[data->cmd + 1][0])
	{
		ft_printf("%s: %s: No such file or directory\n", argv[0], \
		argv[data->cmd + 1]);
		ft_exit(data, 2);
	}
	if (data->here_doc)
		fd = open(argv[data->cmd + 1], O_CREAT | O_WRONLY | O_APPEND, 0755);
	else
		fd = open(argv[data->cmd + 1], O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (fd == -1)
	{
		ft_printf("%s: %s: Permission denied\n", argv[0], \
		argv[data->cmd + 1]);
		ft_exit(data, 2);
	}
	return (fd);
}

void	ft_here_doc(char **argv, t_data *data)
{
	char	*here_doc;

	if (pipe(data->pipefd) == -1)
		exit(EXIT_FAILURE);
	while (TRUE)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		here_doc = get_next_line(0);
		if (!here_doc)
			ft_exit(data, EXIT_FAILURE);
		if (ft_strlen(here_doc) == ft_strlen(argv[2]) + 1 && \
		!ft_strncmp(here_doc, argv[2], ft_strlen(argv[2])))
		{
			free(here_doc);
			break ;
		}
		ft_putstr_fd(here_doc, data->pipefd[1]);
		free(here_doc);
	}
	ft_close(&data->pipefd[1]);
	ft_dup(data->pipefd[0], STDIN_FILENO, data);
}
