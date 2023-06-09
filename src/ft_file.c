/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 13:24:44 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/14 14:22:36 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	fd = open(argv[data->cmd + 1], O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (fd == -1)
	{
		ft_printf("%s: %s: Permission denied\n", argv[0], \
		argv[data->cmd + 1]);
		ft_exit(data, 2);
	}
	return (fd);
}
