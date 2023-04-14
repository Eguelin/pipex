/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eguelin <eguelin@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:49:30 by eguelin           #+#    #+#             */
/*   Updated: 2023/04/14 17:29:37 by eguelin          ###   ########lyon.fr   */
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
		ft_here_doc(argv, &data);
	else
		ft_dup(ft_open_infile(argv), STDIN_FILENO, &data);
	exit_ft = ft_pipex(argv, env, &data);
	return (exit_ft);
}
