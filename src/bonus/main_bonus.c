/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:49:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/14 16:04:45 by eguelin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		exit_ft;

	ft_set_data(argv, &data);
	if (argc <= 3 || (argc <= 4 && data.here_doc))
	{
		ft_printf("%s: not enough arguments\n", argv[0]);
		return (2);
	}
	if (data.here_doc)
	{
		if (pipe(data.pipefd) == -1)
			exit(EXIT_FAILURE);
		ft_here_doc(argv, &data);
		ft_close(&data.pipefd[1]);
		ft_dup(data.pipefd[0], STDIN_FILENO, &data);
	}
	else
		ft_dup(ft_open_infile(argv), STDIN_FILENO, &data);
	exit_ft = ft_pipex(argv, env, &data);
	return (exit_ft);
}
