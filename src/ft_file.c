/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:24:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/11 19:08:14 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_infile(char **argv)
{
	int	fd;

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
	if (data->here_doc)
		fd = open(argv[data->cmd + 1], O_CREAT | O_WRONLY | O_APPEND, 0755);
	else
		fd = open(argv[data->cmd + 1], O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (fd == -1)
	{
		ft_printf("%s: permission denied: %s\n", argv[0], \
		argv[data->cmd + 1]);
		ft_exit(data, EXIT_FAILURE);
	}
	return (fd);
}

void	ft_here_doc(char **argv, t_data *data)
{
	char	*line;
	char	*here_doc;

	here_doc = NULL;
	while (TRUE)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		line = get_next_line(0);
		if (!line)
			exit(EXIT_FAILURE);
		if (ft_strlen(line) == ft_strlen(argv[2]) + 1 && \
		!ft_strncmp(line, argv[2], ft_strlen(argv[2])))
		{
			free(line);
			break ;
		}
		here_doc = ft_strjoin_free(here_doc, line);
		if (!here_doc)
			exit(EXIT_FAILURE);
	}
	ft_putstr_fd(here_doc, data->pipefd[1]);
	free(here_doc);
}
