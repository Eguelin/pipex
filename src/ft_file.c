/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:24:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/12 18:18:31 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_open_infile(char **argv)
{
	int	fd;

	if (!argv[1][0] || access(argv[1], F_OK))
	{
		ft_printf("%s: cannot open %s: No such file\n", argv[0], argv[1]);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s: cannot open %s: Permission denied\n", argv[0], argv[1]);
		return (-1);
	}
	return (fd);
}

int	ft_open_outfile(char **argv, t_data *data)
{
	int	fd;

	if (!argv[data->cmd + 1][0])
	{
		ft_printf("%s: cannot create %s: Directory nonexistent\n", argv[0], \
		argv[data->cmd + 1]);
		ft_exit(data, 2);
	}
	if (data->here_doc)
		fd = open(argv[data->cmd + 1], O_CREAT | O_WRONLY | O_APPEND, 0755);
	else
		fd = open(argv[data->cmd + 1], O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (fd == -1)
	{
		ft_printf("%s: cannot create %s: Permission denied\n", argv[0], \
		argv[data->cmd + 1]);
		ft_exit(data, 2);
	}
	return (fd);
}

void	ft_here_doc(char **argv, t_data *data)
{
	char	*here_doc;

	while (TRUE)
	{
		ft_putstr_fd("heredoc> ", STDOUT_FILENO);
		here_doc = get_next_line(0);
		if (!here_doc)
			exit(EXIT_FAILURE);
		if (ft_strlen(here_doc) == ft_strlen(argv[2]) + 1 && \
		!ft_strncmp(here_doc, argv[2], ft_strlen(argv[2])))
		{
			free(here_doc);
			break ;
		}
		ft_putstr_fd(here_doc, data->pipefd[1]);
		free(here_doc);
	}
}
